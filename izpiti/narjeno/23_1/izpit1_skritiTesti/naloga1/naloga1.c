
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    
    FILE* vhodna = fopen(argv[1], "rb");
    FILE* izhodna = fopen(argv[2], "wb");

    unsigned char* buffer = calloc(100000, sizeof(unsigned char));
    size_t numB = fread(buffer, sizeof(unsigned char), 100000, vhodna);

    for (size_t i = 0; i < numB; i++)
    {
        if (buffer[i] == 0x1B && buffer[i+1] == 0xC9) i++;
        fwrite(&buffer[i], sizeof(unsigned char), 1, izhodna);        
    }
    
    return 0;
}
