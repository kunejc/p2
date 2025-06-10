
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


int dobiVisino(Vozlisce *start){
    int visina = 1;
    while (start->dol != NULL)
    {
        start = start->dol;
        visina++;
    }
    return visina;
}


Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina){
    
    Vozlisce *levi = start;
    Vozlisce *desni = start;
    Vozlisce *trenutno = start;
    int visina = dobiVisino(start);

    Vozlisce **novaVozlisca = malloc(visina * sizeof(Vozlisce*));
    for (int i = 0; i < visina; i++) {
        novaVozlisca[i] = malloc(sizeof(Vozlisce));
        novaVozlisca[i]->vsebina = vsebina++;
        if (i == visina-1) novaVozlisca[i]->dol = NULL;
        else novaVozlisca[i]->dol = novaVozlisca[i+1];
    }
    


    if (mesto == 0)
    {   
        for (size_t i = 0; i < visina-1; i++)
        {
            novaVozlisca[i]->desno = trenutno;
            trenutno = trenutno->dol;
        }
        novaVozlisca[visina-1]->desno = trenutno;
        
        return novaVozlisca[0];
        
    }
    else {
        for (size_t i = 0; i < mesto-1; i++)
        {
            levi = levi->desno;
        }
        desni = levi->desno;
    
        for (size_t i = 0; i < visina; i++)
        {
            levi->desno = novaVozlisca[i];
            novaVozlisca[i]->desno = desni;
            if(i != visina-1) {
                levi = levi->dol;
                desni = desni->dol;
            }
        }
        
        

    }

    
    return start;




}

//=============================================================================

#ifndef test

int main() {
    
    return 0;
}

#endif
