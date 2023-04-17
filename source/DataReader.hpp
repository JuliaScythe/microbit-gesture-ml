#ifndef __UTIL_DATAREADER_INCLUDED
#define __UTIL_DATAREADER_INCLUDED

#include "util.hpp"
#include <vector>

struct ProcessedData {
    float ax_max;
    float ax_min;
    float ax_std;
    float ax_peaks;
    float ax_total;

    float ay_max;
    float ay_min;
    float ay_std;
    float ay_peaks;
    float ay_total;   

    float az_max;
    float az_min;
    float az_std;
    float az_peaks;
    float az_total;
};


class DataReader {
public:
    DataReader(int samples, codal::Accelerometer *source);
    ~DataReader();
    ProcessedData getProcessedData();
    void takeSample();

    bool isDataReady();

private:
    codal::Accelerometer* source;

    int numSamples;
    int sampleHead;

    bool dataReady;

    float* samplesX;
    float* samplesY;
    float* samplesZ;
};


#endif