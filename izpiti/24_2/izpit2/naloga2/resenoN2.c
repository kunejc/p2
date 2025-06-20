
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
 * 02..03: zaporedje podatkov a_1, a_1, a_2, a_2, a_3, a_3, ... (a_i != a_{i+1})
 * 04..05: nikoli nimamo ve"c kot dveh zaporednih vozli"s"c z enako vrednostjo
 *         komponente <podatek>
 * 01, 06..10: splo"sni primeri
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

//=============================================================================

// po potrebi dopolnite ...

void obdelaj(Vozlisce* zacetek) {
    Vozlisce* node = zacetek;
    int c=0;
    while(node)
    {
        if(node->naslednje&&node->podatek==node->naslednje->podatek)
        {
            c=1;
            Vozlisce* end = node->naslednje;
            while(end&&end->podatek==node->podatek)
            {
                c++;
                end=end->naslednje;
            }
            node->podatek=c*node->podatek;
            node->naslednje=end;
        }
        node=node->naslednje;

    }
}

#ifndef test

    

int main() {
    

    return 0;
}


#endif