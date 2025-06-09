#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>



int main(int argc, char *argv[]) {
    FILE *vhodna = fopen(argv[1], "rb");
    int vrstica, stolpec, sirina, visina, index;
    sscanf(argv[2], "%d", &vrstica);
    sscanf(argv[3], "%d", &stolpec);
    uint8_t *rgb = malloc(3*sizeof(uint8_t));
    char buffer[100];

    fgets(buffer, sizeof(buffer), vhodna); //P6
    fgets(buffer, sizeof(buffer), vhodna); //s v
    sscanf(buffer, "%d %d", &sirina, &visina);
    // sirina -= '0';
    // visina -= '0';
    fgets(buffer, sizeof(buffer), vhodna); //255

    index = vrstica*sirina + stolpec +1;
    for (size_t i = 0; i < index; i++)
    {
        fread(&rgb[0], sizeof(uint8_t), 1, vhodna);
        fread(&rgb[1], sizeof(uint8_t), 1, vhodna);
        fread(&rgb[2], sizeof(uint8_t), 1, vhodna);
    }
    printf("%d %d %d", rgb[0], rgb[1], rgb[2]);




    
    fclose(vhodna);
    return 0;
}