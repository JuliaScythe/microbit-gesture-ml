from intelhex import IntelHex

def augment_hex():
    mainhex = IntelHex("MICROBIT.hex")
    mainhex.loadbin('source/model.ml4f', offset=0x40000)
    mainhex.write_hex_file("MICROBIT2.hex")

if __name__=="__main__":
    augment_hex()


