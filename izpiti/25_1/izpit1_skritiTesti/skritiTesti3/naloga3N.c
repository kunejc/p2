
/*
 * Zagon posami"cnega primera:
 *
 * gcc -Dtest test01.c naloga3.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Javni testni primeri:
 *
 * 02--05: 
 *    V teh primerih se ne preverja istovetnost vozli"s"c vhodnega seznama in
 *    izhodne konstrukcije.
 *
 * 01, 06--10: 
 *    V teh primerih se preverja tudi istovetnost vozli"s"c vhodnega seznama
 *    in izhodne konstrukcije.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

Zunanje* porazdeli(Notranje* zacetek, int k) {
    
    Zunanje **zunanji = malloc(k * sizeof(Zunanje*));
    for (size_t i = 0; i < k; i++)
    {
        zunanji[i] = malloc(sizeof(Zunanje));       
        zunanji[i]->dol = NULL;
        zunanji[i]->prvo = NULL;
        zunanji[i]->zadnje = NULL;
        if (i > 0) zunanji[i-1]->dol = zunanji[i];
    }
    
    Notranje *trenutno = zacetek;
    
    while (trenutno != NULL)
    {
        for (size_t i = 0; i < k; i++)
        {

            
            if (zunanji[i]->prvo == NULL)
            {
                zunanji[i]->prvo = trenutno;
                zunanji[i]->zadnje = trenutno;
                trenutno = trenutno->desno;
                zunanji[i]->zadnje->desno = NULL;
            }
            else {
                zunanji[i]->zadnje->desno = trenutno;
                zunanji[i]->zadnje = trenutno;
                trenutno = trenutno->desno;
                zunanji[i]->zadnje->desno = NULL;
            }         
            
            if (trenutno == NULL) break;
        }   
    }
    return zunanji[0];
}

#ifndef test
int main() {

    return 0;
}
0;
#endif
