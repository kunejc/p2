#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>



int main(int argc, char *argv[]) {

    int vrstica = atoi(argv[2]);
    int stolpec = atoi(argv[3]);
    int sirina, visina;
    FILE *datoteka = fopen(argv[1], "rb");
    uint8_t rgb[] = {0, 0, 0};
    char *buffer = malloc(100*sizeof(char));

    
    fgets(buffer, 100, datoteka); //P6

    fgets(buffer, 100, datoteka); 
    sscanf(buffer,"%d %d", &sirina, &visina); //sirina visina
    
    fgets(buffer, 100, datoteka); //255



    int index = vrstica*sirina + stolpec + 1;
    // printf("%d*%d + %d + 1 = %d\n",vrstica, sirina, stolpec, index);
    // printf("%d\n", index);

    for (size_t i = 0; i < index; i++)
    {
        fread(&rgb[0], sizeof(uint8_t), 1, datoteka);
        fread(&rgb[1], sizeof(uint8_t), 1, datoteka);
        fread(&rgb[2], sizeof(uint8_t), 1, datoteka);
    }
    printf("%d %d %d\n", rgb[0], rgb[1], rgb[2]);

    
    
















    
    fclose(datoteka);
    return 0;
}