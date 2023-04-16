#include "ml.hpp"
#include "MicroBit.h"


size_t MODEL_LOCATION = 0x40000;

float output[3];
uint8_t* arena;

int categorise(ProcessedData data)
{
    const float test_input[] = {0.9981025, 0, 0.740098, 0.1428571, 0.8138962, 0.1456103, 0, 0.5203705, 0.2857143, 0.8988151, 1, 1.0117648, 0.4434038, 0.4285714, 0.142982};

    const ml4f_header_t *model = (ml4f_header_t*)MODEL_LOCATION;
    // run model here
    // see https://github.com/microsoft/ml4f/blob/main/sample/ml4f.c

    arena = (uint8_t*) malloc(model->arena_bytes); 
    memcpy(arena + model->input_offset, &test_input, 15*4);

    if(arena == nullptr) {
        microbit_panic(723);
    } 

    int result = invoke(model, arena);

    memcpy(output, arena + model->output_offset, 3*4);
    //free(arena);

    return 1000*output[1];
}

typedef void (*model_fn_t)(const ml4f_header_t *model, uint8_t *arena);

int invoke(const ml4f_header_t *model, uint8_t *arena) {
    model_fn_t fn = (model_fn_t)((const uint8_t *)model + model->header_size + 1);
    fn(model, arena);
    return 0;
}
