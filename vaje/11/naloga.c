
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
    









    return NULL;
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
