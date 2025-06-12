
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

int TABELA[] = {6759, 9358, 7936, 121, 7432, 1981, 8801, 6971, 4379, 9910, 86, 3877, 2428, 7178, 1684, 3523, 7877, 6233, 7496, 2643, 9647, 7385, 5103, 1515, 12, 7750, 9450, 3627, 182, 8912, 1764, 1299, 1450, 2378, 3079, 7653, 3647, 2725, 9527, 1584, 5771, 4528, 5656, 9113, 5269, 6393, 488, 3261, 8232, 1980, 2801, 4462, 9010, 3862, 832, 5440, 5057, 4845, 3274, 3056, 333, 3539, 6996, 8468, 396, 3728, 176, 3760, 8447, 5495, 7883, 2347, 1521, 1164, 6311, 4133, 3012, 9565, 3590, 8142, 8894, 3961, 2700, 3572, 2446, 2286, 692, 1373, 3660, 5404, 3557, 462, 279, 4159, 5939, 3990, 1803, 3892, 1304, 9872, 9346, 6915, 8553, 4981, 312, 5657, 8161, 9915, 6809, 1196, 8651, 4779, 6285, 2241, 7044, 40, 6497, 545, 9426, 3717, 1351, 6128, 7005, 5745, 6304, 285, 6647, 6306, 911, 9596, 2313, 8849, 6240, 298, 5565, 1431, 6729, 9282, 5154, 203, 62, 7533, 6169, 4949, 4820, 6552, 6456, 7191, 6179, 8580, 6464, 2209, 80, 7238, 2633, 5189, 4000, 2888, 18, 7868, 9207, 4624, 1387, 6671, 708, 6935, 160, 1954, 9622, 7402, 1404, 4356, 817, 4067, 6463, 8090, 6490, 5909, 2443, 1526, 5512, 6224, 5401, 9677, 9451, 5453, 3652, 3325, 8502, 9878, 9061, 3423, 615, 8042, 4016, 945, 9165, 98, 7844, 2030, 1056, 7804, 8772};

int main() {
    int n = sizeof(TABELA) / sizeof(int);

    Notranje* zacetek = zgradi(TABELA, n);

    printf("Vhod: ");
    izpisiNotranje(zacetek);
    printf("\n");

    Zunanje* glava = porazdeli(zacetek, 5);

    printf("Izhod: ");
    izpisiZunanje(glava);
    printf("\n");

    pocistiZunanje(glava);
    return 0;
}
