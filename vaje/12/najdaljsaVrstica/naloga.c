#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



int main(int argc, char *argv[]) {

    char buffer[1000];
    char najVrstica[1000];
    int najDolzina = 0;
    FILE *vhodnaDatoteka = fopen(argv[1], "r");
    while(fgets(buffer, 1000, vhodnaDatoteka) != NULL) {
        if (strlen(buffer) > najDolzina) {
            strcpy(najVrstica, buffer);
            najDolzina = strlen(buffer);
        }
    };
    FILE *izhodnaDatoteka = fopen(argv[2], "w");
    fputs(najVrstica, izhodnaDatoteka);
    
    
    fclose(vhodnaDatoteka);
    fclose(izhodnaDatoteka);












    return 0;
}