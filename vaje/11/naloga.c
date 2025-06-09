
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int vsotaI(Vozlisce* zacetek) {
    Vozlisce *trenutno = zacetek;
    int sum = 0;
    while (trenutno != NULL)
    {
        sum += trenutno->podatek;
        trenutno = trenutno->naslednje;
    }
    // sum += trenutno->podatek;
    
    return sum;
}

int vsotaR(Vozlisce* zacetek) {
    if(zacetek == NULL) return 0;
    return vsotaR(zacetek->naslednje) + zacetek->podatek;
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    Vozlisce *trenutno = zacetek;
    // Vozlisce *pred = zacetek;
    
    Vozlisce *novo = malloc(sizeof(Vozlisce));
    novo->podatek = element;
    novo->naslednje = NULL;

    if(zacetek == NULL) return novo;
    if (element <= trenutno->podatek)
    {
        novo->naslednje = trenutno;
        return novo;
    }
    while (trenutno->naslednje != NULL)
    {
        if(trenutno->naslednje->podatek > element) {
            novo->naslednje = trenutno->naslednje;
            trenutno->naslednje = novo;
            return zacetek;
        } 
        trenutno = trenutno->naslednje;
    }
    trenutno->naslednje = novo;
        
    return zacetek;
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {
    if(zacetek == NULL || zacetek->podatek > element) 
    {
        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->podatek = element;
        novo->naslednje = zacetek;
        return novo;
    }
    zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);
    return zacetek;







    return NULL;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
