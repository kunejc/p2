
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

int TABELA[] = {9704, 2985, 3015, 6172, 1211, 7841, 1834, 5092, 2160, 287, 5192, 8278, 1109, 8946, 4030, 5467, 8545, 2456, 7597, 4045, 3581, 2666, 9342, 9484, 827, 8225, 1373, 2502, 6643, 8909, 1634, 5677, 6157, 79, 7329, 5795, 7911, 7483, 9286, 5901, 9279, 7553, 8071, 2841, 9552, 5469, 300, 1803, 6555, 5464, 8860, 8966, 5203, 5216, 2984, 8822, 808, 1421, 3042, 6925, 3883, 3426, 8700, 5252, 166, 3707, 3074, 3133, 8686, 637, 2898, 9696, 2353, 1048, 9263, 5663, 5424, 7514, 5667, 2741, 1756, 2183, 2238, 4774, 3411, 7958, 5887, 1229, 4289, 3170, 3272, 4975, 7220, 5314, 2304, 9673, 4274, 2395, 5074, 1163, 4531, 8430, 9596, 9832, 6919, 5354, 4566, 3149, 8919, 7289, 2881, 8975, 1544, 4607, 6510, 6160, 9188, 4672, 1746, 2576, 1270, 652, 7092, 5671, 2088, 6108, 4270, 2164, 4400, 4843, 6360, 9205, 2332, 6682, 6488, 6340, 5596, 8394, 175, 9911, 7780, 3993, 4985, 4480, 585, 6973, 4388, 5856, 115, 8265, 6309, 3179, 9322, 9307, 7077, 3519, 1919, 412, 9906, 4808, 6829, 8803, 9442, 2616, 1510, 367, 3846, 9609, 1959, 1287, 2850, 1128, 1008, 5164, 1012, 8891, 9441, 9481, 1514, 6159, 9750, 3102, 8648, 3087, 5098, 2054, 9386, 5636, 5889, 4229, 9298, 7578, 6483, 3178, 7390, 5878, 5912, 497, 1099, 6855, 906, 2144, 8402, 2914, 6427, 7451, 6683, 4022, 7906, 4978, 228, 5989, 6924, 7295, 7143, 3374, 7669, 2567, 1781, 269, 3454, 4558, 3390, 8694, 494, 2858, 488, 5813, 3432, 2923, 4937, 6895, 1387, 1072, 7170, 3313, 6964, 7282, 4670, 9881, 4667, 7472, 4204, 6174, 5473, 226, 9421, 7402, 3538, 8594, 1450, 1963, 1444, 5885, 485, 8740, 5263, 4307, 2549, 899, 434, 8042, 4254, 190, 8768, 3205, 3093, 9611, 6047, 2931, 5870, 7313, 9521, 2511, 6383, 9544, 3572, 4795, 4398, 1717, 5240, 6626, 5035, 3709, 8379, 8022, 7006, 2426, 5032, 3495, 6841, 5867, 8586, 6030, 8065, 2996, 8425, 1175, 7661, 8689, 8186, 6506, 396, 8296, 541, 5115, 5391, 4027, 2719, 6394, 8495, 1776, 2554, 5978, 3119, 9805, 154, 8345, 6892};

int main() {
    int n = sizeof(TABELA) / sizeof(int);
    int najElement = maksimum(TABELA, n);
    Notranje** element2naslov = calloc(najElement + 1, sizeof(Notranje*));

    Notranje* zacetek = zgradi(TABELA, n, element2naslov);

    printf("Vhod: ");
    izpisiNotranje(zacetek);
    printf("\n");

    Zunanje* glava = porazdeli(zacetek, 74);

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
