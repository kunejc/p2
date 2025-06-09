#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>



int main(int argc, char *argv[]) {
    FILE *vhodnaDat = fopen(argv[1], "r");
    FILE *izhodnaDat = fopen(argv[2], "w");

    char buffer[100];
    int sirina, visina;
    uint8_t *rgb = malloc(3*sizeof(uint8_t));
    uint8_t sivina;

    //beri/beri header
    fgets(buffer, 100, vhodnaDat); //P6
    fputs("P5\n", izhodnaDat);
    
    fgets(buffer, 100, vhodnaDat); sscanf(buffer, "%d %d", &sirina, &visina);//v s 
    fputs(buffer, izhodnaDat);
    
    fgets(buffer, 100, vhodnaDat); //255
    fputs(buffer, izhodnaDat);
 
    for (size_t i = 0; i < sirina*visina; i++)
    {
        fread(&rgb[0], sizeof(uint8_t), 1, vhodnaDat);
        fread(&rgb[1], sizeof(uint8_t), 1, vhodnaDat);
        fread(&rgb[2], sizeof(uint8_t), 1, vhodnaDat);

        sivina = (30*rgb[0] + 59*rgb[1] + 11*rgb[2])/100;

        fwrite(&sivina, sizeof(uint8_t), 1, izhodnaDat);
    }
    


    fclose(vhodnaDat);
    fclose(izhodnaDat);
    return 0;
}