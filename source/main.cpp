#include <stdio.h>

#include "MicroBit.h"
#include "util.hpp"
#include "Model.hpp"
#include "DataReader.hpp"


MicroBit uBit;

const int SAMPLES = 60;
const int SAMPLEDELAY = 1000 / 30;

int main() {
    uBit.init();
    setMicroBit(&uBit);
    print("Initializing...\n");

    Model m = Model();
    DataReader r = DataReader(SAMPLES, &uBit.accelerometer, m.normData);

    while(true) {
        r.takeSample();
        if(r.isDataReady()) {
            m.classify(r.getProcessedData());
        }
        uBit.sleep(SAMPLEDELAY);
    }

    microbit_panic(700);
    return 0;
}