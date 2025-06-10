
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
    
    size_t h = 1;
    Vozlisce* zacetek = start;
    
    while (zacetek->dol)
    {
        h++;
        zacetek = zacetek->dol;
    }
    zacetek = start;

    Vozlisce** nodes = malloc(h * sizeof(Vozlisce*));
    for (size_t i = 0; i < h; i++)
    {   
        nodes[i] = malloc(sizeof(Vozlisce));
        nodes[i]->vsebina = vsebina + i;
        nodes[i]->desno = NULL;
        nodes[i]->dol = NULL;
    }
    
    Vozlisce* prejsnja = zacetek;
    Vozlisce* naslednja = zacetek->desno;


    if (mesto == 0) 
    {
        start = nodes[0];
        for (size_t i = 0; i < h; i++)
        {
            nodes[i]->desno = zacetek;
            if (i > 0)
            {
                nodes[i-1]->dol = nodes[i];
            }
            zacetek = zacetek->dol;
        }
    }
    else {
        for (size_t i = 0; i < mesto-1; i++)
        {
            prejsnja = prejsnja->desno;
            naslednja = naslednja->desno;
        }

        for (size_t i = 0; i < h; i++)
        {
            prejsnja->desno = nodes[i];
            nodes[i]->desno = naslednja;
            if (i > 0)
            {
                nodes[i-1]->dol = nodes[i];
            }
            prejsnja = prejsnja->dol;
            if (naslednja) naslednja = naslednja->dol;
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
