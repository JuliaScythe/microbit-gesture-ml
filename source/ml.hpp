#ifndef ML_HPP_INCLUDED
#define ML_HPP_INCLUDED

#include "data.hpp"
#include <cstddef>
#include <stdint.h> 
#include <stdlib.h>
#include <string.h>

extern size_t MODEL_LOCATION;
extern double output[3];

typedef struct ml4f_header {
    uint32_t magic0;
    uint32_t magic1;
    uint32_t header_size;
    uint32_t object_size;
    uint32_t weights_offset;
    uint32_t test_input_offset;
    uint32_t test_output_offset;
    uint32_t arena_bytes;
    uint32_t input_offset;
    uint32_t input_type;
    uint32_t output_offset;
    uint32_t output_type; 
    uint32_t reserved[4];
    uint32_t input_shape[0];
} ml4f_header_t;

int categorise(ProcessedData data);

int invoke(const ml4f_header_t *model, uint8_t *arena);

#endif // ML_HPP_INCLUDED