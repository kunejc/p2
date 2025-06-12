
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

int TABELA[] = {1106, 1578, 8632, 6840, 101, 2692, 8433, 6456, 818, 6859, 9074, 3674, 1558, 1117, 4948, 6215, 4190, 4621, 4394, 9654, 9411, 8583, 8186, 2473, 7087, 2746, 3871, 2483, 450, 1308, 3684, 5350, 4109, 2390, 36, 9368, 124, 1684, 8217, 6815, 7524, 5729, 8376, 132, 9554, 452, 2629, 5215, 116, 6557, 5467, 9485, 4110, 2065, 9538, 7066, 8670, 6328, 2867, 9748, 6088, 9432, 109, 8941, 2693, 6436, 4826, 4348, 2199, 7054, 6151, 873, 3463, 9960, 8116, 1298, 5585, 2893, 2667, 823, 7753, 5483, 7380, 2267, 9182, 2330, 9747, 2513, 3562, 7457, 8188, 7472, 359, 7803, 7768, 885, 5697, 9969, 8065, 5885, 329, 3580, 6778, 5549, 8212, 8577, 5248, 1648, 5034, 7402, 6878, 1690, 9139, 1085, 9528, 16, 9527, 2118, 3979, 696, 7574, 1920, 4871, 7871, 529, 6295, 8681, 4762, 3804, 2750, 8992, 8571, 1751, 5294, 799, 6614, 5405, 6923, 3185, 8634, 8026, 5073, 718, 4586, 3791, 7288, 1654, 7928, 6013, 9376, 9347, 444, 7959, 5084, 7677, 2535, 8579, 7787, 2194, 388, 8365, 5160, 9966, 5715, 4977, 6221, 575, 5683, 9277, 5698, 7694, 7532, 4815, 610, 8731, 2093, 4840, 2764, 4162, 3184, 3812, 1781, 2408, 2584, 47, 5856, 5368, 1834, 8637, 8762, 5996, 8287, 678, 6074, 4553, 9560, 354, 8368, 9010, 7530, 5005, 2534, 1661, 9039, 4745, 2477, 3423, 4878, 6356, 4928, 6786, 5189, 9107, 8860, 6897, 8590, 7405, 195, 5288, 7640, 3132, 4596, 5343, 2495, 5030, 1880, 5535, 4734, 1142, 4381, 7793, 9464, 4669, 4482, 9675, 3863, 9023, 1541, 3049, 3203, 6783, 6963, 9241, 3913, 627, 5578, 4169, 8859, 5176, 7873, 9205, 7186, 6906, 8889, 5843, 4620, 2536, 2221, 7814, 4852, 1933, 1725, 6323, 3440, 4454, 6269, 5987, 3714, 4034, 6610, 8270, 5052, 8428, 5292, 4038, 9600, 2928, 2070, 3799, 7327, 7815, 6586, 3442, 9835, 5214, 5898, 2081, 5264, 7977, 5645, 9591, 7441, 6122, 5894, 3444, 3508, 7200, 7672, 9043, 2939, 7967, 4343, 4626, 3892, 959, 6922, 8760, 8626, 7660, 7779, 4419, 1247, 2726, 3186, 8562, 5635, 9473, 4578, 1096, 7923, 8445, 356, 8423, 1678, 3711, 1145, 8864, 4799, 2032, 8680, 8056, 4531, 5151, 1066, 2733, 6294, 5713, 4086, 9659, 2699, 2934, 1557, 4355, 632, 648, 6188, 9643, 2258, 102, 216, 583, 4078, 5521, 4366, 7303, 151, 973, 80, 2657, 3377, 4661, 2719, 6797, 9902, 4858, 4222, 7286, 4979, 3877, 3296, 5876, 9497, 6256, 8175, 4781, 9934, 9271, 6498, 2520, 9974, 7144, 3232, 6045, 2602, 7931, 8337, 5072, 8117, 2202, 5059, 9532, 8951, 6982, 3994, 7481, 8244, 263, 1986, 6528, 3202, 3356, 2791, 8002, 6782, 693, 7890, 6197, 2795, 4594, 7033, 4410, 3915, 9667, 1535, 1086, 9155, 384, 7148, 874, 3740, 7125, 9072, 9520, 7781, 8206, 6101, 9561, 5435, 3397, 5146, 9455, 1826, 1138, 2565, 3041, 8392, 58, 5077, 2840, 6800, 9319, 6344, 2083, 337, 9353, 6181, 7491, 9302, 7339, 7887, 410, 3930, 2067, 8908, 7400, 4315, 2403, 5571, 422, 629, 9183, 7131, 2284, 6143, 7311, 8345, 1027, 7028, 1322, 588, 1960, 2434, 6193, 350, 7680, 913, 6473, 3646, 4676, 3044, 8607, 9504, 6120, 279, 3768, 4307, 4073, 4318, 3422, 1109, 1456, 6216, 6902, 809};

int main() {
    int n = sizeof(TABELA) / sizeof(int);
    int najElement = maksimum(TABELA, n);
    Notranje** element2naslov = calloc(najElement + 1, sizeof(Notranje*));

    Notranje* zacetek = zgradi(TABELA, n, element2naslov);

    printf("Vhod: ");
    izpisiNotranje(zacetek);
    printf("\n");

    Zunanje* glava = porazdeli(zacetek, 15);

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
