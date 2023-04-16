#include "MicroBit.h"
#include "ml.hpp"

void print(ManagedString s);

MicroBit uBit;
MicroBitDisplay *display;

double smoothedX;
double smoothedY;
double smoothedZ;

// Should be kept in sync with the ml-machine settings
const int numSamples = 60;
const int samplesPerSecond = 4;

// We'll use these as a circular buffer to store past data
int prevDataBufferHead = 0; // the index of the next point to write data to
double prevDataX[numSamples];
double prevDataY[numSamples];
double prevDataZ[numSamples];

/*
    Converts a 0-60 index into the index space of the circular buffer
*/
int cIndex(int mappedIndex) {
    return (mappedIndex + prevDataBufferHead) % numSamples;
}

int prevDataPush(int x, int y, int z) {
    prevDataBufferHead = (prevDataBufferHead + 1) % numSamples;
    print(ManagedString(prevDataBufferHead) + "\n");
    prevDataX[prevDataBufferHead] = x;
    prevDataY[prevDataBufferHead] = y;
    prevDataZ[prevDataBufferHead] = z;

    return 0;
}

void print(ManagedString s) {
    for (int i=0; i<s.length(); i++) {
        uBit.serial.putc(s.charAt(i));
    }
}

void print(char* s, int l) {
    for (int i=0; i<l; i++) {
        uBit.serial.putc(s[i]);
    }
}

int main()
{
    uBit.init();

    print("Started\n");

    smoothedX = uBit.accelerometer.getX() / 1000.0;
    smoothedY = uBit.accelerometer.getY() / 1000.0;
    smoothedZ = uBit.accelerometer.getZ() / 1000.0;
    //microbit_panic( 123 );

    print(MODEL_LOCATION, 8);

    while(true) {
        double x = uBit.accelerometer.getX() / 1000.0;
        double y = uBit.accelerometer.getY() / 1000.0;
        double z = uBit.accelerometer.getZ() / 1000.0;
        smoothedX = smoothedX*0.75 + x*0.25;
        smoothedY = smoothedY*0.75 + y*0.25;
        smoothedZ = smoothedZ*0.75 + z*0.25;
        
        prevDataPush(x,y,z);

        uBit.sleep(1000 / samplesPerSecond);
    }

    microbit_panic( 999 );
}

