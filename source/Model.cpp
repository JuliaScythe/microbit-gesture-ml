#include "Model.hpp"
#include "MicroBit.h"

const int* NORM_BASE = (int*) 0x40000;
const int* MODEL_BASE = (int*) 0x40078;

#define MAX_OUTPUTS 256

Model::Model() {

    //this->header = (ModelHeader*) model_data; // who needs type safety anyway
    
    this->normData = (NormData*) NORM_BASE;
    this->header = (ModelHeader*) (MODEL_BASE);

    
    if (this->header->magic0 != 0x30470f62) {
        microbit_panic(701);
    }

    this->arena = (uint8_t*) malloc(this->header->arena_bytes);

    this->numOutputs = this->header->input_shape[2];

    if (this->numOutputs > MAX_OUTPUTS) {
        microbit_panic(702);
    }


}

Model::~Model() {
    free(this->arena);
}

typedef void (*model_fn_t)(const ModelHeader *model, uint8_t *arena);

int Model::classify(ProcessedData data)
{

    //this->dump(data);
    //const float test_input[] = {0.9981025, 0, 0.740098, 0.1428571, 0.8138962, 0.1456103, 0, 0.5203705, 0.2857143, 0.8988151, 1, 1.0117648, 0.4434038, 0.4285714, 0.142982};
    
    memcpy(this->arena + this->header->input_offset, &data, 15*4);

    volatile model_fn_t fn = (model_fn_t)((const uint8_t *)this->header + this->header->header_size + 1);  

    fn(this->header, this->arena);


    float output[MAX_OUTPUTS];
    memcpy(output, this->arena + this->header->output_offset, this->numOutputs*4);

    if (this->numOutputs >= 3) {
    print("\n a: "); print((int)(output[0]*10000.0));
    print(" b: "); print((int)(output[1]*10000.0));
    print(" c: "); print((int)(output[2]*10000.0));
    }

    int maxi = -1;
    float max = -1;
    for (int i=0; i<this->numOutputs; i++) {
        if (output[i] > max) {
            maxi = i; max = output[i];
        }
    }

    return maxi;
}

/**
 * For use in debugging 
 */
void Model::dump(ProcessedData data) {

    print("\n\n\n>>>>>>>> X <<<<<<<<");
    print("\n max: "); print((int)(data.ax_max*10000.0));
    print("\n min: "); print((int)(data.ax_min*10000.0));
    print("\n std: "); print((int)(data.ax_std*10000.0));
    print("\n pek: "); print((int)(data.ax_peaks*10000.0));
    print("\n tot: "); print((int)(data.ax_total*10000.0));

    print("\n>>>>>>>> Y <<<<<<<<");
    print("\n max: "); print((int)(data.ay_max*10000.0));
    print("\n min: "); print((int)(data.ay_min*10000.0));
    print("\n std: "); print((int)(data.ay_std*10000.0));
    print("\n pek: "); print((int)(data.ay_peaks*10000.0));
    print("\n tot: "); print((int)(data.ay_total*10000.0));

    print("\n>>>>>>>> Z <<<<<<<<");
    print("\n max: "); print((int)(data.az_max*10000.0));
    print("\n min: "); print((int)(data.az_min*10000.0));
    print("\n std: "); print((int)(data.az_std*10000.0));
    print("\n pek: "); print((int)(data.az_peaks*10000.0));
    print("\n tot: "); print((int)(data.az_total*10000.0));

}
