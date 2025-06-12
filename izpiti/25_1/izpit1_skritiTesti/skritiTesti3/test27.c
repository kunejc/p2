
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

int TABELA[] = {7802, 3380, 6317, 9219, 5785, 7958, 7425, 9454, 6979, 3415, 2537, 2796, 8770, 8718, 3518, 2909, 8104, 2524, 2563, 5298, 8884, 6503, 4503, 680, 3081, 721, 9713, 44, 7753, 6407, 6608, 9288, 7216, 5486, 3778, 5435, 834, 3883, 1119, 1351, 8627, 7332, 5483, 5804, 9196, 9930, 6635, 9959, 2341, 2508, 2565, 615, 4645, 6646, 2087, 9494, 2959, 8637, 3591, 6572, 8575, 2154, 4420, 7508, 4720, 4473, 8287, 1251, 6101, 3064, 4040, 2257, 7513, 1839, 1279, 4230, 6748, 6763, 8573, 857, 3487, 1681, 5897, 7926, 6166, 2831, 4127, 8580, 1157, 4280, 1615, 5527, 7480, 2335, 5458, 6774, 2233, 9968, 8619, 5135, 5736, 8355, 5689, 5642, 6705, 1320, 8053, 3546, 6312, 867, 6596, 6968, 392, 5100, 93, 793, 4539, 2731, 1399, 3941, 9159, 7069, 8062, 2205, 7449, 539, 9182, 2795, 4257, 6353, 6028, 1327, 5724, 1384, 5117, 8834, 6803, 1655, 2956, 4889, 6432, 9400, 1977, 6760, 39, 4041, 7350, 1679, 5932, 382, 7320, 5997, 767, 2593, 1242, 4506, 8141, 983, 6230, 5671, 7168, 8820, 2717, 1587, 4899, 4267, 1659, 6489, 5673, 1785, 8941, 7191, 267, 3867, 5863, 9142, 6468, 1573, 4718, 4541, 7189, 9507, 2254, 4233, 3532, 7285, 807, 2656, 9579, 4940, 8417, 799, 9373, 7567, 8070, 1613, 6252, 7629, 9237, 2728, 2867, 8871, 9583, 7617, 3478, 9995, 6089, 6260, 5619, 6088, 2557, 1322, 2942, 4202, 4914, 1435, 7372, 2030, 4869, 4142, 3224, 8405, 3822, 8674, 1726, 3161, 109, 1423, 7429, 2612};

int main() {
    int n = sizeof(TABELA) / sizeof(int);
    int najElement = maksimum(TABELA, n);
    Notranje** element2naslov = calloc(najElement + 1, sizeof(Notranje*));

    Notranje* zacetek = zgradi(TABELA, n, element2naslov);

    printf("Vhod: ");
    izpisiNotranje(zacetek);
    printf("\n");

    Zunanje* glava = porazdeli(zacetek, 198);

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
