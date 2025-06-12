
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

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

int TABELA[] = {1108, 1091, 3983, 2078, 901, 9692, 3502, 521, 9495, 7224, 1843, 2785, 5197, 4566, 6052, 3590, 664, 4097, 6272, 1954, 8587, 5047, 4216, 4587, 6927, 9489, 7098, 4854, 4563, 5593, 819, 7222, 977, 9290, 1243, 5455, 4319, 8957, 8272, 5025, 9088, 5678, 4858, 7219, 2016, 3918, 4989, 5771, 8006, 5526, 8652, 5899, 6862, 9381, 2470, 5798, 6665, 8903, 7846, 9873, 3587, 8642, 3948, 5837, 8123, 1002, 6164, 6331, 9223, 2047, 2991, 6742, 5349, 7067, 5672, 7979, 2481, 5662, 5386, 502, 6664, 1722, 2856, 3617, 7305, 3273, 7684, 7946, 9231, 7994, 734, 8294, 3169, 2935, 124, 3837, 1623, 9244, 4099, 6909, 6618, 7187, 3060, 2008, 7770, 7932, 5659, 7850, 4205, 8673, 3920, 6460, 7983, 2295, 9937, 9813, 6133, 5498, 4460, 9854, 6274, 5669, 2823, 2100, 5819, 796, 8313, 9042, 4090, 4541, 9588, 2643, 1510, 3051, 2226, 5514, 6739, 3385, 4924, 2740, 2662, 3702, 9645, 7873, 9098, 7227, 371, 6049, 1256, 7411, 179, 1835, 3626, 545, 2781, 9019, 5532, 2578, 6607, 3308, 8314, 2674, 3589, 6730, 4434, 7070, 5376, 6222, 7476, 2903, 9051, 6906, 308, 7830, 4539, 3940, 714, 1437, 9113, 7629, 4888, 3055, 5579, 9087, 6674, 3373, 8752, 6350, 6364, 3567, 6627, 3066, 9365, 9800, 9791, 8601, 1512, 2956, 2396, 2700, 3004, 8477, 7350, 5596, 6770, 2529, 4643, 5470, 6853, 9496, 1404, 6332, 6695, 7693, 9882, 5246, 9976, 7812, 752, 6991, 5965, 5477, 1310, 7490, 6753, 9833, 3052, 5866, 8814, 9488, 4945, 6799, 3386, 7791};

int main() {
    int n = sizeof(TABELA) / sizeof(int);
    int najElement = maksimum(TABELA, n);
    Notranje** element2naslov = calloc(najElement + 1, sizeof(Notranje*));

    Notranje* zacetek = zgradi(TABELA, n, element2naslov);

    printf("Vhod: ");
    izpisiNotranje(zacetek);
    printf("\n");

    Zunanje* glava = porazdeli(zacetek, 7);

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
