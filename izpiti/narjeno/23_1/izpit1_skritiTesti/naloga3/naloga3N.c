
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
int dobiVisino(Vozlisce *start) {
    Vozlisce *curr = start; 
    int sum = 1;
    while (curr->dol != NULL) {
        curr = curr->dol;
        sum++;
    }
    return sum;
}
int dobiSirino(Vozlisce *start) {
    Vozlisce *curr = start; 
    int sum = 1;

    while (curr->desno != NULL) {
        curr = curr->desno;
        sum++;
    }
    return sum;
}

Vozlisce* ustvariStolpec(int visina, int vsebina) {
    Vozlisce **stolpec = calloc(visina, sizeof(Vozlisce*));
    
    for (size_t i = 0; i < visina; i++)
    {
        stolpec[i] = calloc(1, sizeof(Vozlisce));
        stolpec[i]->vsebina = vsebina;
        vsebina++;
        if(i > 0) stolpec[i-1]->dol = stolpec[i];
    }
    return stolpec[0];
}



Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina) {
    Vozlisce *rtn = start;
    int visina = dobiVisino(start);
    int sirina = dobiSirino(start);

    
    Vozlisce *stolpec = ustvariStolpec(visina, vsebina);

    // printf("Stolpec vsebina: ");
    // Vozlisce *temp = stolpec;
    // while (temp != NULL) {
    //     printf("%d ", temp->vsebina);
    //     temp = temp->dol;
    // }
    // printf("\n");
    // printf("sirina: %d, visina: %d, mesto: %d, vsebina:%d\n", sirina, visina, mesto, vsebina);
    
    Vozlisce *trenutnoLevo = start;
    Vozlisce *trenutnoDesno = start;
    if (mesto == 0)
    {
        rtn = stolpec;
        for (size_t i = 0; i < visina; i++)
        {
            stolpec->desno = trenutnoLevo;

            stolpec = stolpec->dol;
            trenutnoLevo = trenutnoLevo->dol;
        }
        
    }
    else if(mesto < sirina) { 
        for (size_t i = 0; i < mesto-1; i++)
        {
            trenutnoLevo = trenutnoLevo->desno;
            
        }
        trenutnoDesno = trenutnoLevo->desno;

        for (size_t i = 0; i < visina; i++)
        {
            trenutnoLevo->desno = stolpec;
            stolpec->desno = trenutnoDesno;

            trenutnoLevo = trenutnoLevo->dol;
            stolpec = stolpec->dol;
            trenutnoDesno = trenutnoDesno->dol;
        }

    }
    else {
        for (size_t i = 0; i < sirina-1; i++)
        {
            trenutnoLevo = trenutnoLevo->desno;
            
        }
        for (size_t i = 0; i < visina; i++)
        {
            trenutnoLevo->desno = stolpec;

            trenutnoLevo = trenutnoLevo->dol;
            stolpec = stolpec->dol;
        }
    }
    







    return rtn;
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
