#include "MicroBit.h"
#include "ml.hpp"
#include <cstdio>

void print(ManagedString s);

MicroBit uBit;
MicroBitDisplay *display;

double smoothedX;
double smoothedY;
double smoothedZ;

/*
    Converts a 0-60 index into the index space of the circular buffer
*/
int cIndex(int mappedIndex) {
    return (mappedIndex + prevDataBufferHead) % numSamples;
}

inline void print(ManagedString s) {
    for (int i=0; i<s.length(); i++) {
        uBit.serial.putc(s.charAt(i));
    }
}


inline void print(char* s, int l) {
    for (int i=0; i<l; i++) {
        uBit.serial.putc(s[i]);
    }
}


inline void print(int i) {
    char buf[10];
    int n=snprintf(buf, 10, "%d", i);
    print(buf,n);
}

int main()
{
    uBit.init();

    print("======================= BOOT =======================\n");

    smoothedX = uBit.accelerometer.getX() / 1000.0;
    smoothedY = uBit.accelerometer.getY() / 1000.0;
    smoothedZ = uBit.accelerometer.getZ() / 1000.0;

    ProcessedData test_data;
    //categorise(test_data);
    int data1 = 1000*output[0];


    ManagedString s = ManagedString(data1);
    for (int i=0; i<s.length(); i++) {
        uBit.serial.putc(s.charAt(i));
    }

    print("\n");
    print(data1);
    print("\n");
    print(ManagedString((int)(1000*output[1])));
    print("\n");
    print(ManagedString((int)(1000*output[2])));
    print("\nDone init\n");
    print("Arena at ");
    print(ManagedString((int) arena));
    print("\n");

    data1++;
    print(data1);

    int counter = 0;

    while(true) {

        double x = uBit.accelerometer.getX() / 1000.0;
        double y = uBit.accelerometer.getY() / 1000.0;
        double z = uBit.accelerometer.getZ() / 1000.0;
        smoothedX = smoothedX*0.75 + x*0.25;
        smoothedY = smoothedY*0.75 + y*0.25;
        smoothedZ = smoothedZ*0.75 + z*0.25;
        
        prevDataX[1] = 5.0;

        prevDataPush(x,y,z);

        print(counter);                

        if (counter++ > 59) {
            print(".\n");
            ProcessedData data = processData(prevDataX,prevDataY,prevDataZ);
            categorise(data);
        }

        uBit.sleep(1000 / samplesPerSecond);
    }

    release_fiber();
    microbit_panic( 999 );
}

