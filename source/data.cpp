#include "data.hpp"
#include <math.h>

ProcessedData processData(float *x, float *y, float *z)
{
    return ProcessedData();
}

float mean(float *data)
{
    float total = sum(data);
    return total / numSamples;
}

float stdDev(float *data)
{
    float avg = mean(data);
    float squareErrors[numSamples];
    for(int i=0; i<numSamples; i++) {
        float err = data[i] - avg; 
        squareErrors[i] = err * err;
    }
    float avgError = mean(squareErrors);
    return sqrtf(avgError);
}

float totalAccel(float *data)
{   
    float total = 0;
    for(int i=0; i<numSamples; i++) {
        total += abs(data[i]);
    }
    return total;
}

float sum(float *data)
{
    float total = 0;
    for(int i=0; i<numSamples; i++) {
        total += data[i];
    }
    return total;
}

float min(float *data) {
    float min = data[0];
    for(int i=0; i<numSamples; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

float max(float *data) {
    float max = data[0];
    for(int i=0; i<numSamples; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

int peaks(float *data)
{
    //TODO
    return 0;
}
