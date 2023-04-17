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

    DataReader r = DataReader(SAMPLES, &uBit.accelerometer);
    Model m = Model();

    while(true) {
        r.takeSample();
        if(r.isDataReady()) {
            print("\nData Ready!\n");
            m.classify(r.getProcessedData());
        }
        uBit.sleep(SAMPLEDELAY);
    }

    microbit_panic(700);
    return 0;
}