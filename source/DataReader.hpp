#ifndef __UTIL_DATAREADER_INCLUDED
#define __UTIL_DATAREADER_INCLUDED

#include "util.hpp"
#include <vector>

struct ProcessedData {
    union {
        struct {
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
        struct {
            float data[15];
        };
    };
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

    static ProcessedData normalizeData(ProcessedData input);
};

const float norm_mins[15] = {
    -0.06800000000001666,
    -2.040000000000049,
    0.009523227995569575,
    0,
    6.076000000002287,
    0.17199999999998308,
    -2.0400000000000498,
    0.006520579607066559,
    0,
    12.155999999997661,
    -0.9760000000000207,
    -2.040000000000049,
    0.007765465695429917,
    0,
    33.576000000000235
};   

const float norm_maxs[15] = {
    2.039999999999999,
    -0.11600000000002882,
    1.533451470408599,
    7,
    121.38800000000013,
    2.039999999999999,
    0.11999999999997185,
    1.3039079490165355,
    7,
    101.61600000000091,
    2.039999999999999,
    -1.0200000000000247,
    1.7498636350087768,
    7,
    152.6120000000001
};



#endif