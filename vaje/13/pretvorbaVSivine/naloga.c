#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>



int main(int argc, char *argv[]) {
    FILE *vhodna = fopen(argv[1], "rb");
    FILE *izhodna = fopen(argv[2], "wb");
    int sirina, visina;
    char buffer[100];
    uint8_t rgbs[4];

    // printf("test");

    fgets(buffer, sizeof(buffer), vhodna); //P6
    fputs("P5\n", izhodna);
    
    fgets(buffer, sizeof(buffer), vhodna); //v s
    sscanf(buffer, "%d %d", &sirina, &visina);
    fputs(buffer, izhodna);
    
    fgets(buffer, sizeof(buffer), vhodna); //255
    fputs(buffer, izhodna);

    size_t maxIndex = sirina * visina;
    // printf("maxIndex = %ld", maxIndex);
    
    for (size_t i = 0; i < maxIndex; i++)
    {
        fread(&rgbs[0], sizeof(uint8_t), 1, vhodna);
        fread(&rgbs[1], sizeof(uint8_t), 1, vhodna);
        fread(&rgbs[2], sizeof(uint8_t), 1, vhodna);
        rgbs[3] = (30*rgbs[0] + 59*rgbs[1] + 11*rgbs[2])/100;
        fwrite(&rgbs[3], sizeof(uint8_t), 1, izhodna);
    }
    
    fclose(vhodna);
    fclose(izhodna);
    



































    return 0;
}