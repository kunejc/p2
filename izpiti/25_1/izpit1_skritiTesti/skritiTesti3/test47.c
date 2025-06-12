
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

int TABELA[] = {862, 162, 3094, 76, 507, 1716, 6762, 7781, 7670, 4337, 7825, 1281, 4528, 7049, 2599, 1319, 2984, 4660, 1089, 854, 7331, 255, 2612, 7397, 5308, 9284, 3839, 4891, 4327, 4953, 4356, 3261, 78, 17, 5371, 2887, 7402, 2178, 6856, 9638, 981, 4988, 762, 1763, 2733, 3667, 726, 7408, 8455, 7579, 775, 5963, 5634, 7710, 6224, 2515, 4758, 504, 2730, 3987, 730, 3309, 3176, 7127, 94, 227, 6482, 9331, 2450, 7383, 4023, 9725, 3538, 3773, 9009, 2132, 8654, 1001, 935, 2666, 7208, 6266, 7144, 2330, 5112, 9012, 4766, 9606, 8330, 1430, 3863, 7475, 5085, 4774, 5684, 9828, 4245, 6178, 9166, 4364, 7779, 8318, 2430, 3128, 9388, 39, 6185, 3193, 7064, 664, 2000, 9277, 1558, 1539, 2827, 2320, 5011, 776, 5975, 3466, 365, 4279, 2959, 8962, 3520, 21, 7611, 7767, 6322, 5094, 481, 7248, 2940, 2271, 7017, 8785, 1877, 9880, 4923, 9242, 1534, 8481, 9894, 9403, 5256, 4590, 5777, 7247, 9676, 8626, 2942, 5525, 2904, 3052, 7257, 4864, 2895, 6814, 5326, 5860, 8206, 6277, 6575, 5140, 1277, 5887, 9405, 7394, 7449, 7952, 6787, 5187, 533, 3291, 2784, 798, 1545, 8774, 1713, 245, 5850, 4373, 7210, 4971, 7790, 3777, 1407, 8734, 9223, 7272, 4212, 3627, 802, 446, 1513, 4676, 5314, 9233, 7430, 3640, 9609, 2672, 7965, 3648, 2518, 159, 547, 810, 2681, 3074, 9408, 5995, 4583, 8666, 2581, 2371, 3912, 571, 6797, 1445, 8168, 3745, 2512, 6730, 3392, 7509, 5475, 6893, 6599, 3744, 5188, 6549, 2967, 6580, 2408, 615, 2022, 8845, 119, 167, 8287, 8202, 6007, 7697, 4498, 2133, 9193, 1152, 7624, 9409, 570, 266, 8985, 1419, 9820, 3410, 5377, 5985, 9887, 2059, 9543, 955, 8528, 4674, 5508, 9431, 25, 2291, 3926, 9381, 5944, 822, 5017, 9338, 3885, 7435, 887, 6039, 9386, 4492, 7989, 903, 9682, 2395, 4639, 4350, 9619, 7760, 4360, 8690, 4347, 7057, 6271, 6439, 6770};

int main() {
    int n = sizeof(TABELA) / sizeof(int);
    int najElement = maksimum(TABELA, n);
    Notranje** element2naslov = calloc(najElement + 1, sizeof(Notranje*));

    Notranje* zacetek = zgradi(TABELA, n, element2naslov);

    printf("Vhod: ");
    izpisiNotranje(zacetek);
    printf("\n");

    Zunanje* glava = porazdeli(zacetek, 82);

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
