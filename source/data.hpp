#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED


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

// Should be kept in sync with the ml-machine settings
static const int numSamples = 60;
static const int samplesPerSecond = 4;

// We'll use these as a circular buffer to store past data
static int prevDataBufferHead = 0; // the index of the next point to write data to
static float prevDataX[numSamples];
static float prevDataY[numSamples];
static float prevDataZ[numSamples];

ProcessedData processData(float *x, float *y, float *z);

void prevDataPush(int x, int y, int z);

float mean(float* data);
float stdDev(float* data);
float totalAccel(float* data);
float sum(float* data);
float min(float* data);
float max(float* data);
int peaks(float* data);

#endif // DATA_HPP_INCLUDED