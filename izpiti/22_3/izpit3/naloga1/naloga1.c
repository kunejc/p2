
/*
Ro"cno testiranje (npr. za primer 01):

gcc naloga1.c
./a.out vhod01.pgm 150 izhod01.pgm
cmp izhod01.pgm ref01.pgm

Samodejno testiranje:

export name=naloga1
make test

Lahko si pomagate tudi s programom hexdump:

hexdump -C datoteka.pgm

Testni primeri:

01: primer iz besedila
02..07: vsaka pika je bodisi 0 bodisi 255
08..12: splo"sni primeri

Testne datoteke:

test*.par: argumenti ukazne vrstice
vhod*.pgm: vhodna slika
ref*.pgm: pri"cakovana izhodna slika
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

int main(int argc, char** argv) {

    FILE* vhodna = fopen(argv[1], "rb");
    FILE* izhodna = fopen(argv[3], "wb");
    int prag, sirina, visina;
    sscanf(argv[2], "%d", &prag);
    
    char buffC[100];
    uint8_t buffN;
    
    fgets(buffC, 100*sizeof(char), vhodna); //P5
    fputs(buffC, izhodna);
    
    fgets(buffC, 100*sizeof(char), vhodna); //w h
    sscanf(buffC, "%d %d", &sirina, &visina);
    fputs(buffC, izhodna);
    
    fgets(buffC, 100*sizeof(char), vhodna); //255
    fputs(buffC, izhodna);
    
    while (fread(&buffN, sizeof(uint8_t), 1, vhodna) == 1)   
    {
        if (buffN >= prag) buffN = 255;
        else buffN = 0;
        fwrite(&buffN, sizeof(uint8_t), 1, izhodna);

    }
    









    return 0;
}
