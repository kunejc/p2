#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_ZNAKOV 200000


uint8_t odstrani(uint8_t vhod, int mesta) {
    int mask = 0xFF; // Start with all bits set (11111111)

    mask = mask >> mesta; // Right shift to create the mask
    
    vhod = vhod & mask;
    return vhod;
}

short zdruzi(uint8_t leva, uint8_t desna) {
    uint16_t levaN = leva << 6;
    uint16_t rez = desna + levaN;
    return (short)rez;
}

int main(int argc, char *argv[]){

    FILE *vhodna = fopen(argv[1], "rb");
    FILE *izhodna = fopen(argv[2], "wb");

    // short znaki[200000];
    int count = 0;


    uint8_t *buffer = calloc(1, sizeof(uint8_t));
    uint8_t *buffer2 = calloc(1, sizeof(uint8_t));
    short *izhod = calloc(1, sizeof(short));

    while(fread(buffer, sizeof(uint8_t), 1, vhodna)){
        if(((*buffer)>>7) & 1) {
            fread(buffer2, sizeof(uint8_t), 1, vhodna);
            *izhod = zdruzi(odstrani(*buffer, 3), odstrani(*buffer2, 2));
            fwrite(izhod, sizeof(short), 1, izhodna);
            count++;
            
        }
        else {
            *izhod = (short) *buffer;
            fwrite(izhod, sizeof(short), 1, izhodna);            
            count++;
        }
    }

    
    // for (size_t i = 0; i < count; i++)
    // {
    //     fwrite(&znaki[i], sizeof(short), 1, izhodna);
    // }

    fclose(vhodna);
    fclose(izhodna);
    














    return 0;
}