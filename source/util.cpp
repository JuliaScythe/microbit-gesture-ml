#include "util.hpp"
#include <stdio.h>

void print(ManagedString s) {
    for (int i=0; i<s.length(); i++) {
        u->serial.putc(s.charAt(i));
    }
}


void print(char* s, int l) {
    for (int i=0; i<l; i++) {
        u->serial.putc(s[i]);
    }
}


void print(int i) {
    char buf[10];
    int n= snprintf(buf, 10, "%d", i);
    print(buf,n);
}

void setMicroBit(codal::MicroBit *uBit) {
    u = uBit;
}



float mean(float *data, int length)
{
    float total = sum(data, length);
    return total / length;
}

float stdDev(float *data, int length)
{
    float avg = mean(data, length);
    float squareErrors[length];
    for(int i=0; i<length; i++) {
        float err = data[i] - avg; 
        squareErrors[i] = err * err;
    }
    float avgError = mean(squareErrors, length);
    return sqrtf(avgError);
}

float totalAccel(float *data, int length)
{   
    float total = 0;
    for(int i=0; i<length; i++) {
        total += abs(data[i]);
    }
    return total;
}

float sum(float *data, int length)
{
    float total = 0;
    for(int i=0; i<length; i++) {
        total += data[i];
    }
    return total;
}

float min(float *data, int length) {
    float min = data[0];
    for(int i=0; i<length; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

float max(float *data, int length) {
    float max = data[0];
    for(int i=0; i<length; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

int peaks(float *data, int length, int currentHead)
{
    //TODO

    // note for tri -- when indexing the array, to get the data in the right order you need to add currentHead to the array index mod length.
    // since data is a circular buffer
    // we don't do this anywhere else in the file since this is the only place where the order of the data matters.
     
    return 0;
}

float normalize(float x, float max, float min)
{
    if(max == min) return 0;
    
    return (x-min)/(max-min);
}
