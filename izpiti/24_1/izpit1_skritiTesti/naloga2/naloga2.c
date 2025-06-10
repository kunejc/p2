
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -Dtest testXY.c naloga2.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 *
 * Javni testni primeri:
 *
 * 02..03: n <= 2000, k = 1, D >= 2
 * 04..05: n <= 2000, D >= k + 1
 * 01, 06..08: n <= 2000
 * 09..10: n <= 100000
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

//=============================================================================

// po potrebi dopolnite ...

void obdelaj(Vozlisce* start, int k) {

    Vozlisce* sprednji = start;
    Vozlisce* zadnji = start;
    int sum = sprednji->podatek;

    for (int i = 0; i < k-1; i++)
    {
        sprednji = sprednji->naslednje;
        sum += sprednji->podatek;
    }
    while (sprednji->naslednje != NULL)
    {
        if (sprednji->naslednje->podatek == sum)
        {
            sprednji->naslednje = sprednji->naslednje->naslednje;
        }
        else {
            sprednji = sprednji->naslednje;
            sum += sprednji->podatek;
            sum -= zadnji->podatek;
            zadnji = zadnji->naslednje;

        }
        
    }
    
    
}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo <obdelaj> testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin 
    // (gcc naloga2.c).
    return 0;
}

#endif
