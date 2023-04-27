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

    uBit.display.printChar('!');

    while(true) {
        r.takeSample();
        if(r.isDataReady()) {
            int result = m.classify(r.getProcessedData());

            char buf[3];
            snprintf(buf, 3, "%d", result);

            uBit.display.printChar(buf[0]);
        }
        uBit.sleep(SAMPLEDELAY);
    }

    microbit_panic(700);
    return 0;
}