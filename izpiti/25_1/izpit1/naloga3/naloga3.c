
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
    
    Zunanje **rezultat = calloc(k, sizeof(Zunanje*));
    
    rezultat[0] = malloc(sizeof(Zunanje));
    Zunanje *izhod = rezultat[0];

    for (size_t i = 1; i < k; i++)
    {   
        rezultat[i] = malloc(sizeof(Zunanje));
        rezultat[i-1]->dol = rezultat[i];
        rezultat[i-1]->prvo = NULL;
        rezultat[i-1]->zadnje = NULL;
    }
    rezultat[k-1]->dol = NULL;
    rezultat[k-1]->prvo = NULL;
    rezultat[k-1]->zadnje = NULL;
    

    Notranje *trenutno = zacetek;
    for (size_t i = 0; i < k; i++)
    {
        if(trenutno->desno == NULL) break;
        rezultat[i]->prvo = trenutno;
        rezultat[i]->zadnje = trenutno;
        // rezultat[i]->prvo->desno = NULL;

        trenutno = trenutno->desno;
    }
    while (1)
    {   
        
        for (size_t i = 0; i < k; i++)
        {
            if(trenutno == NULL) break;

            rezultat[i]->zadnje->desno = trenutno;
            rezultat[i]->zadnje = trenutno;
            trenutno = trenutno->desno;
            rezultat[i]->zadnje->desno = NULL;

        }
        
        if(trenutno == NULL) break;
    }
    for (size_t i = 0; i < k; i++)
    {
        rezultat[i]->zadnje->desno = NULL;
    }
    
    




    return izhod;
    // return NULL;
}

#ifndef test
Notranje* zgradi(int* t, int n, Notranje** element2naslov) {
    Notranje* prvo = NULL;
    Notranje* zadnje = NULL;
    for (int i = 0; i < n; i++) {
        Notranje* v = calloc(1, sizeof(Notranje));
        v->podatek = t[i];
        element2naslov[v->podatek] = v;
        if (prvo == NULL) {
            prvo = zadnje = v;
        } else {
            zadnje->desno = v;
            zadnje = zadnje->desno;
        }
    }
    return prvo;
}

void izpisiNotranje(Notranje* zacetek) {
    printf("[");
    Notranje* v = zacetek;
    while (v != NULL) {
        if (v != zacetek) {
            printf(", ");
        }
        printf("%d", v->podatek);
        v = v->desno;
    }
    printf("]");
}

void izpisiZunanje(Zunanje* glava) {
    printf("[");
    Zunanje* v = glava;
    while (v != NULL) {
        if (v != glava) {
            printf(", ");
        }
        izpisiNotranje(v->prvo);
        v = v->dol;
    }
    printf("]");
}

void pocistiNotranje(Notranje* prvo) {
    Notranje* v = prvo;
    while (v != NULL) {
        Notranje* brisi = v;
        v = v->desno;
        free(brisi);
    }
}

void pocistiZunanje(Zunanje* glava) {
    Zunanje* v = glava;
    while (v != NULL) {
        pocistiNotranje(v->prvo);
        Zunanje* brisi = v;
        v = v->dol;
        free(brisi);
    }
}

int maksimum(int* t, int n) {
    int naj = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] > naj) {
            naj = t[i];
        }
    }
    return naj;
}

void preveriIstovetnost(Zunanje* glava, Notranje** element2naslov) {
    Zunanje* z = glava;
    while (z != NULL) {
        Notranje* n = z->prvo;
        while (n != NULL) {
            printf("%d", element2naslov[n->podatek] == n);
            n = n->desno;
        }
        z = z->dol;
    }
}

int TABELA[] = {5, 7, 3, 10, 9, 1, 8, 6, 2, 4};

int main() {
    int n = sizeof(TABELA) / sizeof(int);
    int najElement = maksimum(TABELA, n);
    Notranje** element2naslov = calloc(najElement + 1, sizeof(Notranje*));

    Notranje* zacetek = zgradi(TABELA, n, element2naslov);

    printf("Vhod: ");
    izpisiNotranje(zacetek);
    printf("\n");

    Zunanje* glava = porazdeli(zacetek, 3);

    printf("Izhod: ");
    izpisiZunanje(glava);
    printf("\n");

    printf("Istovetnost vozlisc: ");
    preveriIstovetnost(glava, element2naslov);
    printf("\n");

    pocistiZunanje(glava);
    free(element2naslov);
    return 0;
}

// int main() return 0;
#endif
