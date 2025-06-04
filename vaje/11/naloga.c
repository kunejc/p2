
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int vsotaI(Vozlisce* zacetek) {
    Vozlisce* trenutno = zacetek;
    int vsota = 0;
    while (trenutno != NULL) {
        vsota += trenutno->podatek;
        trenutno = trenutno->naslednje;
    }
    return vsota;
}

int vsotaR(Vozlisce* zacetek) {
    if (zacetek == NULL) return 0;
    int vsota = zacetek->podatek + vsotaR(zacetek->naslednje);
    return vsota;
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    
    Vozlisce* trenutno = zacetek;

    Vozlisce* novoVozlisce = malloc(sizeof(struct Vozlisce));
    novoVozlisce->podatek = element;
    novoVozlisce->naslednje = NULL;

     if (zacetek == NULL || zacetek->podatek >= element) {
        novoVozlisce->naslednje = zacetek;
        return novoVozlisce;
    }
    
    while (trenutno->naslednje != NULL) {
        if (trenutno->naslednje->podatek > element) {
            novoVozlisce->naslednje = trenutno->naslednje;
            trenutno->naslednje = novoVozlisce;
            return zacetek;
        }      
        trenutno = trenutno->naslednje;
    }
    trenutno->naslednje=novoVozlisce;


    return zacetek;
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {
    // popravite / dopolnite ...
    return NULL;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
