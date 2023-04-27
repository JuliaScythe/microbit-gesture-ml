#include "DataReader.hpp"

DataReader::DataReader(int samples, codal::Accelerometer *source) {

    this->source = source;
    this->numSamples = samples;

    this->samplesX = (float*) malloc(4*samples);
    this->samplesY = (float*) malloc(4*samples);
    this->samplesZ = (float*) malloc(4*samples);

    this->sampleHead = 0;

    this->dataReady = false;
}

DataReader::~DataReader() {
    free(this->samplesZ);
    free(this->samplesY);
    free(this->samplesX);
}

ProcessedData DataReader::getProcessedData()
{
    if (!this->dataReady) return ProcessedData();

    ProcessedData result;
    
    result.ax_max = max(this->samplesX, this->numSamples);
    result.ax_min = min(this->samplesX, this->numSamples);
    result.ax_peaks = peaks(this->samplesX, this->numSamples);
    result.ax_std = stdDev(this->samplesX, this->numSamples);
    result.ax_total = sum(this->samplesX, this->numSamples);

    result.ay_max = max(this->samplesY, this->numSamples);
    result.ay_min = min(this->samplesY, this->numSamples);
    result.ay_peaks = peaks(this->samplesY, this->numSamples);
    result.ay_std = stdDev(this->samplesY, this->numSamples);
    result.ay_total = sum(this->samplesY, this->numSamples);

    result.az_max = max(this->samplesZ, this->numSamples);
    result.az_min = min(this->samplesZ, this->numSamples);
    result.az_peaks = peaks(this->samplesZ, this->numSamples);
    result.az_std = stdDev(this->samplesZ, this->numSamples);
    result.az_total = sum(this->samplesZ, this->numSamples);

    return result;
}

void DataReader::takeSample() {
    int x = source->getX();
    int y = source->getY();
    int z = source->getZ();

    this->samplesX[this->sampleHead] = x / 1000.0;
    this->samplesY[this->sampleHead] = y / 1000.0;
    this->samplesZ[this->sampleHead] = z / 1000.0;

    this->sampleHead = (this->sampleHead + 1) % this->numSamples;
    if(sampleHead == 0) this->dataReady = true; // If we've done a full cycle of the buffer


    /*print("\n x: "); print(x);
    print(" y: "); print(y);
    print(" z: "); print(z);
    print(" head: "); print(this->sampleHead);
    print(" ready? "); print(this->dataReady ? "yes" : "no");*/
}

bool DataReader::isDataReady()
{
    return this->dataReady;
}
