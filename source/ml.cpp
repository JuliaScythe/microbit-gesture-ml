#include "ml.hpp"
#include <stdint.h>

char MODEL_LOCATION = 0x40000;

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

int categorise(ProcessedData data)
{
    const ml4f_header_t *model = (ml4f_header_t*)MODEL_LOCATION;
    // run model here
    // see https://github.com/microsoft/ml4f/blob/main/sample/ml4f.c

}
