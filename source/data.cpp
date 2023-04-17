#include "data.hpp"
#include <math.h>

ProcessedData processData(float *x, float *y, float *z)
{
    ProcessedData result;
    
    result.ax_max = max(x);
    result.ax_min = min(x);
    result.ax_peaks = peaks(x);
    result.ax_std = stdDev(x);
    result.ax_total = sum(x);

    result.ay_max = max(y);
    result.ay_min = min(y);
    result.ay_peaks = peaks(y);
    result.ay_std = stdDev(y);
    result.ay_total = sum(y);

    result.az_max = max(z);
    result.az_min = min(z);
    result.az_peaks = peaks(z);
    result.az_std = stdDev(z);
    result.az_total = sum(z);

    return result;
}

void prevDataPush(int x, int y, int z) {
    prevDataBufferHead = (prevDataBufferHead + 1) % numSamples;
    prevDataX[prevDataBufferHead] = x / 1000.0;
    prevDataY[prevDataBufferHead] = y / 1000.0;
    prevDataZ[prevDataBufferHead] = z / 1000.0;

    return;
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
