#ifndef __UTIL_HPP_INCLUDED
#define __UTIL_HPP_INCLUDED

#include "MicroBit.h"

void print(ManagedString s);
void print(char* s, int l);
void print(int i);

static codal::MicroBit* u;

void setMicroBit(codal::MicroBit* uBit);

float mean(float* data, int length);
float stdDev(float* data, int length);
float totalAccel(float* data, int length);
float sum(float* data, int length);
float min(float* data, int length);
float max(float* data, int length);
int peaks(float* data, int length, int currentHead);

float normalize(float x, float max, float min);


#endif