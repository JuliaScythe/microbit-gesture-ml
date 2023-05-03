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
    // data has circular buffer
    int lag = 5;
    float z = 3.5;
    float recent_weight = 0.2; // micro:bit input should be close to stationary data
   
    // process data by applying recent_weight
    float new_data [length] = {};
    new_data[currentHead%length] = data[currentHead%length];
    for (int i=0; i<lag; i++) {
        new_data[(i+currentHead)%length] = data[(i+currentHead)%length];
    }
   
    int peakscounter = 0;
    int signals [length] = {}; // The same circular indexing as data, for consistency
   
    float temp [lag] = {}; // stores the moving window before the current datapoint
    for (int i=0; i<lag; i++) {
        temp[i] = new_data[(i+currentHead)%length];
    }
   
    for (int i=lag; i<length; i++) {
        int baseline = mean(temp, lag);
        int tolerance = z*stdDev(temp, lag);
        if (new_data[(i+currentHead)%length]>baseline+tolerance) {
            signals[(i+currentHead)%length]=1;
            peakscounter+=1;
            new_data[(i+currentHead)%length] = recent_weight*data[(i+currentHead)%length] + (1-recent_weight)*new_data[(i-1+currentHead)%length];
        }
        else if (new_data[(i+currentHead)%length]<baseline+tolerance) {
            signals[(i+currentHead)%length]=-1;
            peakscounter+=1;
            new_data[(i+currentHead)%length] = recent_weight*data[(i+currentHead)%length] + (1-recent_weight)*new_data[(i-1+currentHead)%length];
        }
        else signals[(i+currentHead)%length]=0;
        temp[i%lag] = new_data[(i+currentHead)%length];
    }
    return peakscounter;
}


float normalize(float x, float max, float min)
{
    if(max == min) return 0;
    
    return (x-min)/(max-min);
}
