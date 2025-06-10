
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga2.c
./a.out

Samodejno testiranje:

export name=naloga2
make test

Testni primeri:

01: primer iz besedila
02..04: ena sama vrstica
05..06: vsaka neprazna vrstica je naslovna
07..10: splo"sni primeri

Datoteke:

test*.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in izpi"se rezultat)
test*.dat: testni podatki
test*.out: pri"cakovani izhod testnega programa
test*.res: dejanski izhod testnega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

void vstaviH1(Vozlisce* zacetek) {
    Vozlisce* node = zacetek;
    bool prejsnjaPrzna = true;
    char* vrstica = calloc(2000, sizeof(char));
    do {
        if (node->naslednje == NULL)
        {
            if (prejsnjaPrzna && strcmp(node->niz, "") != 0)
            {
                sprintf(vrstica, "<h1>%s</h1>", node->niz);
                strcpy(node->niz, vrstica);
                prejsnjaPrzna = false;
            }
            break;
        }
        if (strcmp(node->niz, "") != 0)
        {
            if (prejsnjaPrzna && strcmp(node->naslednje->niz, "") == 0)
            {   
                    sprintf(vrstica, "<h1>%s</h1>", node->niz);
                    strcpy(node->niz, vrstica);
            }
            prejsnjaPrzna = false;
        }
        else prejsnjaPrzna = true;
        node = node->naslednje;
    } while (true);
    




}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    






    return 0;
}

#endif
