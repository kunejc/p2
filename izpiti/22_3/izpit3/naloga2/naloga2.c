
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

void vNaslov(char *niz){
    char *pred = "<h1>";
    char *po = "</h1>";
    char zacasna[1001];
    strcpy(zacasna, niz);
    
    strcpy(niz, pred);
    strcat(niz, zacasna);
    strcat(niz, po);

    // free(pred);
    // free(po);
}






void vstaviH1(Vozlisce* zacetek) {
    Vozlisce *trenutno = zacetek;
    int prejsnje = 0;

    while (trenutno->naslednje != NULL)
    {
        if (strlen(trenutno->niz) > 0)
        {
            if (prejsnje == 0 && strlen(trenutno->naslednje->niz)==0)
            {
                vNaslov(trenutno->niz);
            }
            prejsnje = 1;
        }
        else prejsnje = 0;
        
        trenutno = trenutno->naslednje;        
    }
    if (strlen(trenutno->niz) > 0)
    {

        if (prejsnje == 0)
        {
            vNaslov(trenutno->niz);
        }
    }
    







}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    






    return 0;
}

#endif
