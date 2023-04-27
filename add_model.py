from intelhex import IntelHex
import json, struct

normfstring = "<" + "f"*15
model_base = 0x40000

def augment_hex(maxbuf, minbuf):
    mainhex = IntelHex("MICROBIT.hex")
    print("Writing normalisation data at " + hex(model_base))
    mainhex.puts(model_base, maxbuf)
    mainhex.puts(model_base+struct.calcsize(normfstring), minbuf)
    print("Writing model data at " + hex(model_base+struct.calcsize(normfstring)*2))
    mainhex.loadbin('source/model.ml4f', offset=model_base+struct.calcsize(normfstring)*2)
    mainhex.write_hex_file("MICROBIT2.hex")
    print("Done")

def findkeys(d, targetkey):
    output = []
    if isinstance(d, list):
        for v in d:
            output += findkeys(v, targetkey)
    if isinstance(d, dict):
        for k,v in d.items():
            if k == targetkey:
                output.append(v)
            else:
                output += findkeys(v, targetkey)
    return output



def main():
    norm_data = json.load(open("source/model_meta.json"))
    maxbuf = struct.pack(normfstring, *(findkeys(norm_data, 'max')[:-1]))
    minbuf = struct.pack(normfstring, *(findkeys(norm_data, 'min')[:-1]))
    augment_hex(maxbuf, minbuf)


    


    

if __name__=="__main__":
    main()


