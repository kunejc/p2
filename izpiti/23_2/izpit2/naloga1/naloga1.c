
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
#include <stdint.h>

#define MAX_DOLZINA 100000

int main(int argc, char** argv) {
    FILE *vhodna = fopen(argv[1], "rb");
    FILE *izhodna = fopen(argv[2], "wb");

    uint8_t buffer;
    uint8_t arr[MAX_DOLZINA];
    size_t n = 0;
    
    while (fread(&buffer, sizeof(uint8_t), 1, vhodna)) {
        arr[n] = buffer;
        n++;
    }
    
    
    uint8_t prev = NULL;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] == prev) continue;
        fwrite(&arr[i], sizeof(uint8_t), 1, izhodna);
        prev = arr[i];        
    }
    
    fclose(vhodna);
    fclose(izhodna);

    return 0;
}
