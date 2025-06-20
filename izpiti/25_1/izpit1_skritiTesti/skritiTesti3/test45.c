
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

int TABELA[] = {9070, 6536, 8543, 7265, 4677, 3762, 6363, 6996, 1713, 628, 5911, 1455, 3126, 3286, 363, 5227, 6801, 7840, 1326, 3855, 9134, 3900, 7433, 3939, 7036, 159, 2497, 9015, 2158, 5415, 5676, 6148, 9173, 4708, 6952, 5302, 3203, 4989, 7762, 2675, 979, 7093, 2963, 4227, 927, 9984, 4543, 3516, 2604, 8484, 9861, 7181, 7175, 7020, 5671, 8595, 5073, 8460, 8680, 7711, 3024, 8478, 9745, 3347, 6006, 3821, 1657, 2514, 3759, 38, 9470, 9122, 5627, 5216, 6874, 2468, 8609, 4657, 3951, 8453, 9643, 7664, 7001, 5283, 1641, 650, 5646, 8375, 2326, 359, 7215, 6066, 985, 8185, 3279, 3128, 5352, 8184, 1428, 5242, 1538, 8343, 3395, 5384, 2408, 1165, 5138, 9384, 6269, 5721, 2947, 4261, 5512, 8256, 6974, 5590, 3, 240, 9132, 3606, 3861, 4009, 6127, 5557, 3647, 4889, 1740, 5507, 560, 8422, 29, 9517, 7653, 8382, 5661, 118, 5223, 3624, 3618, 803, 3843, 7370, 3130, 5087, 9561, 1707, 3952, 1912, 3915, 2007, 8866, 8005, 4781, 4438, 3085, 5951, 3423, 4461, 8231, 1353, 4313, 5062, 7729, 1377, 1136, 4246, 3171, 8090, 1731, 2312, 2719, 8148, 4775, 8839, 7651, 703, 1649, 3202, 9244, 8234, 9487, 4928, 7751, 6161, 8050, 7200, 4712, 8844, 9415, 4160, 1355, 8129, 8948, 8832, 4539, 9633, 5003, 6983, 3056, 658, 3592, 1191, 6040, 2980, 7187, 9357, 2528, 9751, 9941, 1050, 6160, 8351, 8647, 172, 1777, 8326, 5211, 297, 4136, 9843, 5626, 9346, 5197, 2103, 6135, 8610, 2278, 5631, 9610, 8704, 2707, 3421, 4, 9270, 5470, 6646, 6244, 583, 7794, 3493, 7298, 847};

int main() {
    int n = sizeof(TABELA) / sizeof(int);
    int najElement = maksimum(TABELA, n);
    Notranje** element2naslov = calloc(najElement + 1, sizeof(Notranje*));

    Notranje* zacetek = zgradi(TABELA, n, element2naslov);

    printf("Vhod: ");
    izpisiNotranje(zacetek);
    printf("\n");

    Zunanje* glava = porazdeli(zacetek, 88);

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
