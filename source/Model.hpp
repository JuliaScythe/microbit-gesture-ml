#ifndef __UTIL_MODEL_INCLUDED
#define __UTIL_MODEL_INCLUDED

#include "DataReader.hpp"
#include <cinttypes>

struct ModelHeader {
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
};

class Model {
public:
    Model();
    ~Model();
    int classify(ProcessedData data);

private:
    uint8_t *arena;
    ModelHeader *header;

    void dump(ProcessedData data);
};

const float model_norm_mins[15] = {
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

const float model_norm_maxs[15] = {
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


const unsigned model_data[548] = {
    0x30470f62, 0x46344c4d, 0x00000050, 0x00000888, 0x000003bc, 0x00000000, 0x00000000, 0x00000084, 
    0x00000008, 0x00000001, 0x00000008, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x0000000f, 0x00000000, 0x00000003, 0x00000000, 0x5ff0e92d, 0x6901460f, 0x60391809, 0x60792100, 
    0x46036838, 0x0244f207, 0xecb32410, 0xf2070a01, 0xecf10108, 0xecf30a0e, 0xee607a0e, 0xee210aa7, 
    0xee301a08, 0xee610a20, 0xee301aa8, 0xee220a01, 0xee302a09, 0xee620a21, 0xee302aa9, 0xee230a02, 
    0xee303a0a, 0xee630a22, 0xee303aaa, 0xee240a03, 0xee304a0b, 0xee640a23, 0xee304aab, 0xee250a04, 
    0xee305a0c, 0xee650a24, 0xee305aac, 0xee260a05, 0xee306a0d, 0xee660a25, 0xee306aad, 0xee270a06, 
    0xee307a0e, 0xee300a26, 0xecf10a07, 0xecf30a01, 0xee607a01, 0xee300aa7, 0xeca20a20, 0x3c010a01, 
    0xf207d1b3, 0x68100244, 0xbfb82800, 0x0000f240, 0x6810c201, 0xbfb82800, 0x0000f240, 0x6810c201, 
    0xbfb82800, 0x0000f240, 0x6810c201, 0xbfb82800, 0x0000f240, 0x6810c201, 0xbfb82800, 0x0000f240, 
    0x6810c201, 0xbfb82800, 0x0000f240, 0x6810c201, 0xbfb82800, 0x0000f240, 0x6810c201, 0xbfb82800, 
    0x0000f240, 0x6810c201, 0xbfb82800, 0x0000f240, 0x6810c201, 0xbfb82800, 0x0000f240, 0x6810c201, 
    0xbfb82800, 0x0000f240, 0x6810c201, 0xbfb82800, 0x0000f240, 0x6810c201, 0xbfb82800, 0x0000f240, 
    0x6810c201, 0xbfb82800, 0x0000f240, 0x6810c201, 0xbfb82800, 0x0000f240, 0x6810c201, 0xbfb82800, 
    0x0000f240, 0x6838c201, 0x4300f200, 0x0208f207, 0xecb32403, 0xf2070a01, 0xecf10144, 0xecf30a0e, 
    0xee607a0e, 0xee210aa7, 0xee301a08, 0xee610a20, 0xee301aa8, 0xee220a01, 0xee302a09, 0xee620a21, 
    0xee302aa9, 0xee230a02, 0xee303a0a, 0xee630a22, 0xee303aaa, 0xee240a03, 0xee304a0b, 0xee640a23, 
    0xee304aab, 0xee250a04, 0xee305a0c, 0xee650a24, 0xee305aac, 0xee260a05, 0xee306a0d, 0xee660a25, 
    0xee306aad, 0xee270a06, 0xee307a0e, 0xee300a26, 0xecf10a07, 0xecf30a02, 0xee607a02, 0xee210aa7, 
    0xee301a08, 0xee300a20, 0xeca20a01, 0x3c010a01, 0xf207d1af, 0x46100208, 0xf0002103, 0xe8bdf802, 
    0x29019ff0, 0xedd0b538, 0xd9292a00, 0xeb001d03, 0xecf30281, 0xeef47a01, 0xeef17a62, 0xbfc8fa10, 
    0x2a67eef0, 0xd1f4429a, 0xee022400, 0x46054a10, 0x0a00ed95, 0x0a62ee30, 0xf815f000, 0x42a13401, 
    0x2a00ee32, 0x0a01eca5, 0x2300d8f2, 0x7a00ed90, 0x7a02eec7, 0x42993301, 0x7a01ece0, 0xbd38d8f6, 
    0xd1e12900, 0xeddfbd38, 0xeeb47a29, 0xeef10ae7, 0xd448fa10, 0x7a26eddf, 0x0ae7eeb4, 0xfa10eef1, 
    0xeddfdc3a, 0xeddf7a24, 0xed9f4a24, 0xeddf3a24, 0xed9f3a24, 0xed9f5a24, 0xeddf4a24, 0xed9f5a24, 
    0xeddf6a24, 0xee606a24, 0xeeb77a27, 0xee777a00, 0xee777aa4, 0xeea77ae4, 0xeefd0a83, 0xeea74ae7, 
    0xeef00aa3, 0xeee47a45, 0xee147a00, 0xeee73a90, 0xeea55a80, 0xeee66a80, 0xeef06a00, 0xeef07a66, 
    0xeee76a47, 0xeea66a80, 0xee177a80, 0xeb022a10, 0xee0053c3, 0x47703a10, 0x7a0feddf, 0x7a00eeb7, 
    0x0a27ee87, 0xed9f4770, 0x47700a0c, 0xc2aa0000, 0x42ae0000, 0x3fb8aa3b, 0x4b400000, 0xbf317200, 
    0xb5bfbe8e, 0x3c092f6e, 0x3ab4a000, 0x3d2aadad, 0x3e2aaa28, 0x3efffffb, 0x00000000, 0x3e95bac3, 
    0xbce173d4, 0x3f30b18c, 0xbe35069e, 0xbe09bb6a, 0x3dbfdb3c, 0x3eb85586, 0x3e17de99, 0x3c481319, 
    0xbd9b62ae, 0x3eb0d5f9, 0xbe712562, 0x3e86dbe6, 0xbd0f7366, 0xbe3ae87f, 0xbe8ba518, 0xbd2abf24, 
    0xbd82c3b6, 0xbe0b94e0, 0xbe63a060, 0x3cba52b0, 0x3eb927ff, 0x3ec38f58, 0x3d767aa6, 0xbe85aa58, 
    0xbe700761, 0x3e189346, 0xbe99f416, 0xbeaa16ed, 0x3ca706d6, 0xbe9630b0, 0xbe3069c7, 0x00000000, 
    0xbd9f80ff, 0xbeb3f8cd, 0x3dafe5d2, 0xbda67cb0, 0x3d32df83, 0xbe7f701a, 0x3d9a5d33, 0xbda3a532, 
    0xbbf9fa6f, 0x3e8ca4e9, 0xbedbcddd, 0xbe7ddc55, 0x3ebd8644, 0xbe452821, 0x3dd6f78f, 0x3dca06fc, 
    0x3ecb37c1, 0x3e7c0a67, 0xbe8f6a61, 0xbeb09dfd, 0x3dc46252, 0xbe5aea70, 0x3eff5756, 0xbe137867, 
    0xbe86f5f2, 0xbf019002, 0x3ec44ade, 0x3d308ba8, 0xbcdd2913, 0x3ca3ae57, 0x3beccf59, 0x3d4b2bba, 
    0xbe4a2894, 0xbde86577, 0xbc94d0eb, 0xbea022dd, 0x3eadf171, 0x3f034bbc, 0xbd5ae0a2, 0x3e139ab2, 
    0xbe8d5e26, 0x3e3c2811, 0x3deb895e, 0xbe30a0c9, 0xbe4ca664, 0xbe502be3, 0xbdb98ecc, 0x3ef0b2d6, 
    0xbec3b428, 0x3ed56bfc, 0x3e49ce49, 0x3ca5c13e, 0x3e4aaabf, 0xbea0ffcf, 0x3f326961, 0xbe654948, 
    0xbe6d0796, 0x3d9e7d0d, 0xbd1b0a80, 0x3f282192, 0xbbffda6a, 0xbdefef41, 0x3d6ca366, 0x00000000, 
    0xbe87bd30, 0x3dd30b7a, 0x3e25770b, 0xbd1e3f64, 0xbe18f437, 0xbed4db9b, 0xbe8378ac, 0xbcf5f1ce, 
    0x3d92f24f, 0x3d5af065, 0xbd9d8ed4, 0xbed63b80, 0xbddcb5a4, 0x3df693bd, 0x3d56438c, 0x3e96de3e, 
    0xbe80f07b, 0x3ebff357, 0xbe30d9d6, 0x3e5c48b4, 0xbd836ae1, 0xbdd21fe1, 0x3efc0d53, 0x3e6c51ff, 
    0x3c8c8259, 0xbebb2af6, 0x3df0440f, 0x3f27c23d, 0xbe6f3e76, 0xbe34ff05, 0xbe30c16d, 0xb86d32a6, 
    0x3e77c018, 0xbef2c74c, 0x3ea3a141, 0x3e2185ed, 0x3e9c3bc1, 0xbed2300f, 0xbe51df0a, 0x3dbf285a, 
    0x3cc390f4, 0xbd8bac8c, 0xbec7aada, 0xbc3221ad, 0x3d479005, 0xbeba86cd, 0xbd0808c9, 0xbd09499b, 
    0xbdef6289, 0xbd1df564, 0x3d88083d, 0xbe6108cc, 0x3dc10723, 0x3e9a9bd8, 0x3cf64108, 0xbe865b38, 
    0xbe90b4c2, 0x3d150bf0, 0xbe7218da, 0x3d2d6988, 0x3e11f693, 0x3e4ab479, 0xbe8ee9cb, 0x3e2edd43, 
    0x3d08b6c1, 0x3f4500f0, 0x3ebb8c65, 0x3e07a22b, 0x3d881b11, 0x3d9aba36, 0x3ef1aa94, 0xbdcf7aa2, 
    0xbe91a254, 0xbeb5450a, 0xbdd71d70, 0x3eb5845f, 0xbe29508e, 0xbef579fd, 0x3d971d2e, 0x3e2690c5, 
    0x3e4c3632, 0xbdea969f, 0x3cf2d823, 0x3f424e98, 0x3d5ee00c, 0x3e8e36e7, 0xbea6c29a, 0x3df376d3, 
    0xbe011467, 0x3e8757c6, 0x3f67885c, 0xbdb3abc5, 0x3f864199, 0x3cefe9c2, 0x3ed40bf1, 0x00000000, 
    0xbe0e4b56, 0xbd877310, 0xbe2abe09, 0x3ef46987, 0xbebb0ad2, 0xbea7eabe, 0x3d99e3cc, 0x3eb87bc9, 
    0x3e0c226c, 0x3e5785bc, 0xbdbc7b28, 0xbeb5f03c, 0xbd8f8b58, 0x3df394ce, 0xbe2c2c17, 0x3e42709c, 
    0xbd0d3d04, 0x3eb92de0, 0xbeb570aa, 0x3e6866c6, 0xbcb9a176, 0xbe6c4146, 0x3e8d5ffe, 0x3df5be06, 
    0x3df4b25f, 0xbe661259, 0xbd8865ba, 0x3ed65c74, 0xbe9258b7, 0x3ea72b96, 0x3e54fb44, 0x3ea822a6, 
    0x3e6ed691, 0x3f28cf99, 0x3f2193dd, 0xbf06ef8a, 0x3eefb6da, 0x3ecbcfe9, 0xbe785870, 0x3f272b07, 
    0x3e92ff83, 0x3f3c9cc0, 0xbf2630be, 0xbdd128ec, 0xbf2575b6, 0xbdb2a6b2, 0xbfadb704, 0xbd7728ee, 
    0xbdb878c6, 0xbdd700b5, 0xbe353248, 0xbe35b5b8, 0x3cc24d07, 0x3e2cc186, 0x3ed1c9e4, 0xbe6d46aa, 
    0xbe55b378, 0x3d8cddc5, 0x3d450859, 0xbe0af6d6, 0x3d94c116, 0xbe7a2fc4, 0xbe59c0f5, 0xbefdc2dd, 
    0x3f3ccb97, 0x3e85134e, 0x3e034b41, 0x3e49600a, 0x3e082d25, 0x3f62b3d7, 0x3eaae9d3, 0x3f11ecd5, 
    0x3e37adbe, 0x3c80209b, 0x3ee9be97, 0xbf291408, 0xbec16061, 0x3eb6d860, 0xbf36d80f, 0xbc368590, 
    0x3f096192, 0xbf074186, 0x3f01cd56, 0xbd4d3bab, 0xbedbacf5, 0xbe0d42f2, 0xbf28f089, 0xbe6eb9e3, 
    0xbe5140bc, 0xbdaf37fe, 0x3db4e6e3, 0xbf3c2261, 0x3f9edce0, 0x3e99bd56, 0xbf383835, 0xbfc2b599, 
    0x3eb75477, 0xbd280248, 0x3ef9ee86, 0xbee96bf8, 0xbe9e7eba, 0xbe894680, 0x3ed8ff47, 0xbf1c5a20, 
    0x3e07b35c, 0xbf48c1d8, 0xbec652c1, 0xbc925eda, 0xbe7eac6f, 0xbec18c56, 0xbea6de29, 0xbe5163c3, 
    0x3fc6cac4, 0xbe4573e4, 0x00000000, 0x00000000, 
};


#endif