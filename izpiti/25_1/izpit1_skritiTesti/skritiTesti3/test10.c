
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

Notranje* zgradi(int* t, int n) {
    Notranje* prvo = NULL;
    Notranje* zadnje = NULL;
    for (int i = 0; i < n; i++) {
        Notranje* v = calloc(1, sizeof(Notranje));
        v->podatek = t[i];
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

int TABELA[] = {4474, 8596, 4545, 7806, 8093, 1394, 3129, 9482, 4785, 8931, 9553, 3254, 782, 8748, 6517, 2479, 1128, 6687, 8250, 2349, 825, 3448, 1449, 6603, 8832, 7382, 7839, 7394, 2687, 8205, 4795, 8690, 6828, 8063, 5536, 2516, 5380, 8966, 4998, 3455, 9457, 1615, 9657, 2878, 9722, 7526, 749, 2780, 4357, 4021, 7624, 9473, 2452, 5244, 3147, 3772, 4302, 4799, 7402, 2649, 9312, 6713, 1520, 3108, 6879, 905, 1702, 3185, 7496, 6035, 1755, 9944, 8204, 9034, 613, 7593, 2806};

int main() {
    int n = sizeof(TABELA) / sizeof(int);

    Notranje* zacetek = zgradi(TABELA, n);

    printf("Vhod: ");
    izpisiNotranje(zacetek);
    printf("\n");

    Zunanje* glava = porazdeli(zacetek, 8);

    printf("Izhod: ");
    izpisiZunanje(glava);
    printf("\n");

    pocistiZunanje(glava);
    return 0;
}
