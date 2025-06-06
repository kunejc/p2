#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_ZNAKOV 200000

uint16_t zdruziUint8(uint8_t levi8, uint8_t desni8) {
    uint16_t levi16 = levi8;
    levi16 = levi16 << 6;
    return levi16 + (uint16_t)desni8;
}

uint8_t cleanBits(uint8_t num, int bits) {
    uint8_t cleaner = 255;
    for (size_t i = 0; i < bits; i++)
    {
        cleaner = cleaner >> 1;
    }
    return cleaner & num;
}


int main(int argc, char *argv[]){

    FILE *vhodna = fopen(argv[1], "rb");
    FILE *izhodna = fopen(argv[2], "wb");

    short *stevila = calloc(MAX_ZNAKOV, sizeof(short));
    uint8_t buffer;
    uint8_t buffer2;
    int i = 0;
    int ii = 0;

    //branje
    while (fread(&buffer, sizeof(uint8_t), 1, vhodna) == 1)
    {
        
        if (buffer > 127)
        {
            fread(&buffer2, sizeof(uint8_t), 1, vhodna);
            uint8_t b1 = cleanBits(buffer, 3);
            uint8_t b2 = cleanBits(buffer2, 2);
                       
            stevila[i] = (short)zdruziUint8(b1, b2);
            
            
        } 
        else {
            stevila[i] = (short)buffer;
        }
        i++;
    }

    //pisanje
    while (ii < i)
    {
        fwrite(&stevila[ii],sizeof(short), 1, izhodna);
        ii++;
    }









    // 1 2
    // 2 4
    // 3 8
    // 4 16
    // 5 32
    // 6 64
    // 7 128
    // 8 256














    fclose(vhodna);
    fclose(izhodna);

    return 0;
}