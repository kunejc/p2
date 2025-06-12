
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

int TABELA[] = {9516, 204, 5120, 8713, 1067, 4232, 3758, 6453, 784, 2339, 922, 619, 2063, 2110, 7163, 5138, 3050, 1398, 323, 2780, 2148, 5429, 8532, 7558, 4995, 1593, 7233, 1641, 4492, 8227, 5347, 5874, 3109, 6117, 7549, 2533, 5387, 7456, 5528, 759, 5200, 6488, 6273, 167, 2423, 2085, 1945, 197, 2566, 8506, 9454, 7472, 8928, 4525, 2297, 9062, 3379, 1894, 8053, 7901, 835, 7837, 6604, 4756, 7379, 9504, 8262, 618, 1929, 9058, 8613, 7897, 4802};

int main() {
    int n = sizeof(TABELA) / sizeof(int);

    Notranje* zacetek = zgradi(TABELA, n);

    printf("Vhod: ");
    izpisiNotranje(zacetek);
    printf("\n");

    Zunanje* glava = porazdeli(zacetek, 10);

    printf("Izhod: ");
    izpisiZunanje(glava);
    printf("\n");

    pocistiZunanje(glava);
    return 0;
}
