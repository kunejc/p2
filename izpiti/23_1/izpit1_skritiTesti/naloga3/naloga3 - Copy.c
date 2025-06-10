
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -D=test testXY.c naloga3.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Testni primeri:
 * 02, 03: h = 1
 * 04, 05, 06: mesto = 0
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

// po potrebi dopolnite ...

Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina) {
    
    // dobim h
    size_t h = 1;
    Vozlisce* zacetek = start;
    while (zacetek->dol)
    {
        h++;
        zacetek = zacetek->dol;
    }
    zacetek = start;


    // nardim tabelo novih vozlisc
    Vozlisce** nova = malloc(h * sizeof(Vozlisce*));
    for (size_t i = 0; i < h; i++) {
        nova[i] = malloc(sizeof(Vozlisce));
        nova[i]->vsebina = vsebina + i;
        nova[i]->desno = NULL;
        nova[i]->dol = NULL;
    }
  

   //ustavm vozlisca
    Vozlisce* prejsna = zacetek;
    Vozlisce* naslednja = zacetek->desno;

    for (int i = 0; i < mesto-1; i++)
            {
                prejsna = prejsna->desno;
                naslednja = naslednja -> desno;
            }

 
    for (size_t i = 0; i < h; i++)
    {   
        if (mesto == 0)
        {
            nova[i]->desno = prejsna;
            if (i == 0)
            {
                start = nova[0];
            }
            else {
                nova[i-1]->dol = nova[i];
            }
            
        } else {        
            nova[i]->desno = naslednja;
            prejsna->desno = nova[i];
            if (i > 0)
            {
                nova[i-1]->dol = nova[i];            
            }
        }
                
        prejsna = prejsna->dol;
        if (naslednja != NULL) {
            naslednja = naslednja->dol;
        }
    }

    return start;




}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo <vstaviStolpec> testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga3.c).
    return 0;
}

#endif
