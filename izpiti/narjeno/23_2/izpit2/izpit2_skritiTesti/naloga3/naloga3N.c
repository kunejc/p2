
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
 * 04, 05, 06: preverjajo samo vsoto
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

// void kopirajVozlisce(Vozlisce *rezultatN, Vozlisce *trenutno){
//     rezultatN->dol = NULL;
//     rezultatN->desno = NULL;
    
// }
// kopirajVozlisce(rezultat[n], trenutno);

// int min(int a, int b){
//     if (a > b) return b;
//     return a;
// }


void dodajVozlisce(Vozlisce *start, int vsebina) {
    Vozlisce *novo = calloc(1, sizeof(Vozlisce));
    novo->vsebina = vsebina;
    Vozlisce *curr = start;
    
    while (curr->desno !=NULL) curr = curr->desno;
    curr->desno = novo;
}


Vozlisce* diagonala(Vozlisce* start, int* vsota) {
    *vsota = 0;
    
    Vozlisce *glava = calloc(1, sizeof(Vozlisce));
    
    Vozlisce *trenutno = start;

    int sirina = 0;
    int vrstica = 0;
    while (trenutno->desno != NULL)
    {
        trenutno = trenutno->desno;
        sirina++;
    }
    
    while (1)
    {
        
        trenutno = start;
        for (size_t i = 0; i < vrstica; i++)
        {
            trenutno = trenutno->dol;
        }
        vrstica ++;
        for (size_t i = 0; i < sirina; i++)
        {
            trenutno = trenutno->desno;
        }
        sirina--;
        *vsota += trenutno->vsebina;
        if (vrstica == 1) glava->vsebina = trenutno->vsebina;
        else dodajVozlisce(glava, trenutno->vsebina);
        
        if(sirina < 0) break;
        if(trenutno->dol == NULL) break;



    }
    
    







    return glava;
}






































// Vozlisce* diagonala(Vozlisce* start, int* vsota) {
//     int vsebine[100];
//     int n = 0;
//     int sirina = 0;
//     Vozlisce *trenutno = start;
//     while (trenutno->desno != NULL) {
//         trenutno = trenutno->desno;
//         sirina++;
//     }
//     vsebine[n] = trenutno->vsebina;
//     trenutno = start;
//     while (trenutno->dol != NULL && sirina>0)
//     {
//         n++;
//         trenutno = start;
//         for (size_t i = 0; i < n; i++)
//         {
//             trenutno = trenutno->dol;
//         }
//         for (size_t i = 0; i < sirina-1; i++)
//         {
//             trenutno = trenutno->desno;
//         }
//         sirina--;
//         vsebine[n] = trenutno->vsebina;
//     }
    
//     *vsota = 0;
//     Vozlisce **rezultat = malloc((n+1)*sizeof(Vozlisce*));
//     for (size_t i = 0; i <= n; i++)
//     {
//         rezultat[i] = malloc(sizeof(Vozlisce));

//         rezultat[i]->dol = NULL;

//         rezultat[i]->vsebina = vsebine[i];
//         *vsota += vsebine[i];

//         if (i > 0)
//         {
//             rezultat[i-1]->desno = rezultat[i];
//         }
        

//     }
//     return rezultat[0];
// }

//=============================================================================

#ifndef test


int main() {

    return 0;
}

#endif
