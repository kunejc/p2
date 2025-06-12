
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

int TABELA[] = {9147, 5853, 3229, 3643, 5893, 513, 4998, 1132, 6075, 389, 3741, 1107, 4444, 2184, 4184, 1347, 1773, 5558, 3187, 3114, 6961, 5609, 7145, 1229, 2135, 7930, 6539, 9111, 7502, 724, 1110, 4023, 7437, 1682, 7696, 6460, 7849, 3622, 8454, 6787, 7096, 8557, 5346, 9155, 6112, 7995, 8435, 1032, 3037, 8035, 7512, 5595, 2967, 8292, 5363, 6121, 1182, 7733, 9525, 700, 5143, 996, 8717, 5589, 4350, 5214, 2546, 4532, 7702, 3193, 3946, 6077, 6235, 7093, 368, 5163, 7792, 1200, 4568, 7707, 9479, 8176, 8893, 9572, 2813, 3316, 1318, 4048, 8148, 7030, 8692, 2882, 5176, 862, 3218, 8218, 6639, 574, 5936, 1628, 8393, 4853, 650, 6780, 5543, 6695, 3069, 6807, 3486, 8294, 9688, 9044, 7664, 4513, 7514, 3662, 9501, 8627, 9006, 6380, 1035, 702, 37, 5397, 1613, 3110, 7856, 6018, 1843, 6685, 1232, 2421, 2396, 7475, 3696, 570, 2828, 78, 1744, 4188, 9268, 2162, 6641, 9913, 9736, 548, 9206, 9752, 5657, 2775, 4531, 9871, 8857, 3885, 9358, 5965, 6700, 2023, 8291, 7644, 6036, 9452, 90, 3831, 6993, 6486, 7374, 6777, 8091, 1830, 6495, 254, 653, 5670, 6994, 7825, 117, 2654, 6854, 9386, 9387, 2478, 3742, 9029, 2933, 7270, 2384, 1372, 4115, 3276, 1454, 722, 2711, 5448, 6357, 1778, 5472, 4536, 1770, 3970, 9141, 7143, 2285, 7487, 7824, 3227};

int main() {
    int n = sizeof(TABELA) / sizeof(int);
    int najElement = maksimum(TABELA, n);
    Notranje** element2naslov = calloc(najElement + 1, sizeof(Notranje*));

    Notranje* zacetek = zgradi(TABELA, n, element2naslov);

    printf("Vhod: ");
    izpisiNotranje(zacetek);
    printf("\n");

    Zunanje* glava = porazdeli(zacetek, 1);

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
