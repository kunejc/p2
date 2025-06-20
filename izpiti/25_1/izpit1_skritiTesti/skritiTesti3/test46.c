
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

int TABELA[] = {2325, 3455, 1959, 5849, 3863, 4662, 3134, 2357, 7373, 5773, 7578, 2167, 9298, 7729, 1471, 9061, 800, 3429, 8928, 435, 2369, 4372, 7139, 4005, 5848, 1168, 5332, 2759, 7041, 9027, 4864, 4606, 6496, 9352, 8737, 2683, 4531, 3668, 7330, 1141, 1731, 3820, 1500, 1342, 4449, 4115, 4891, 6127, 3587, 1716, 130, 2051, 5424, 8745, 8151, 6012, 6294, 8439, 6511, 3536, 2979, 5650, 2181, 8702, 99, 8679, 4897, 339, 4225, 8401, 2583, 1265, 8545, 7760, 2634, 2322, 6107, 219, 1905, 1414, 8767, 4990, 3435, 1906, 2828, 9796, 8979, 6396, 377, 1722, 4198, 535, 9857, 6222, 5352, 8459, 9503, 3708, 6369, 918, 7064, 7920, 5201, 4882, 3903, 8260, 2736, 7529, 2636, 4143, 3137, 6759, 7227, 7872, 7461, 7272, 1426, 177, 989, 4070, 1594, 3212, 3743, 9290, 4075, 4092, 1162, 4821, 777, 6758, 9196, 5864, 2464, 3369, 7169, 4504, 4732, 4278, 1148, 7742, 3795, 4842, 3659, 5397, 9530, 2438, 8206, 7978, 9512, 2120, 2106, 7728, 6336, 7429, 8534, 1778, 1300, 4409, 1365, 7305, 4439, 7016, 5655, 8359, 7983, 5345, 1705, 5907, 9807, 2300, 7058, 6760, 5413, 8696, 6961, 1248, 4720, 685, 3393, 1028, 8712, 4297, 436, 8804, 1173, 9279, 7836, 8662, 9931, 4142, 2395, 2795, 1641, 3627, 7791, 8785, 9627, 8373, 5743, 1797, 8108, 547, 7063, 2731, 3713, 7036, 2495, 8644, 5918, 8442, 5837, 3701, 7203, 797, 9033, 4426, 2681, 1307, 2624, 2885, 1291, 8085, 2818, 2091, 7624, 2786, 5021, 9818, 7146, 3551, 5784, 3787, 4009, 1857, 2329, 9655, 5497, 6113, 333, 4057, 9482, 3374, 8355, 9821, 533, 9141, 7924, 6748, 8852, 8271, 9924, 5161, 5059, 8504, 7635, 8208, 8252, 9893, 3079, 6769, 292, 3117, 6013, 2522, 1741, 2617, 8876, 2980, 5449, 7620, 5693, 7574, 9678, 8798, 3068, 8100, 3784, 5335, 362, 6871, 5307, 5528, 4187, 2323, 7377, 5075, 2477, 8471, 4013, 9384, 2429, 5486, 7030, 4319, 3291, 8883, 3376, 782, 9786, 1936, 6497, 1374, 1810, 3115, 6664, 715, 4684, 1065, 898, 5487, 6245, 6788, 3446, 2799, 8304, 5299, 7119, 5351, 2024, 238, 299, 6851, 3763, 106, 2670, 4464, 9808, 7724, 8029, 5648, 5416, 4491, 2315, 7059, 115, 3176, 7999, 8364, 5036, 5841, 456, 9981, 2918, 7778, 5921, 747, 6896, 7932, 3958, 883, 2049, 8658, 9021, 3043, 5019, 5914, 3015, 3815, 6935, 9835, 1223, 805, 3023, 7825, 7726, 328, 9575, 3985, 8005, 3192, 5331, 2993, 8945, 6757, 1924, 9411, 1306, 2174, 7982, 7082, 3945, 2074, 5091, 1828, 3637, 9612, 1032, 326, 2504, 5771, 8823, 7565, 6381, 3883, 9047, 4838, 4294, 4899, 6084, 802, 3267, 4788, 5342, 1545, 5749, 5827, 58, 4086, 6239, 7532, 6614, 1418, 9166, 9429, 3977, 1105, 6460, 1824, 3821, 5003, 7566, 7344, 1888, 5231, 1647, 1152, 6674, 978, 9122, 7603, 9953, 4289, 3591, 4696, 1841, 2937, 3469, 5173, 1057, 7688, 3843, 798, 7273, 6320, 1450, 6429, 6034, 2792, 4352, 570, 5402, 497, 6431, 3458, 9755, 1056, 7871, 3558, 2622, 8107, 1887, 6354, 4261, 3218, 7857, 7907, 3363, 9320, 8569, 12, 1604, 993, 1852, 8858, 2124, 1126, 4835, 6064, 7687, 1189, 6057, 6499, 3300, 4744, 2546, 3148, 7311, 7609, 2878, 686, 4204};

int main() {
    int n = sizeof(TABELA) / sizeof(int);
    int najElement = maksimum(TABELA, n);
    Notranje** element2naslov = calloc(najElement + 1, sizeof(Notranje*));

    Notranje* zacetek = zgradi(TABELA, n, element2naslov);

    printf("Vhod: ");
    izpisiNotranje(zacetek);
    printf("\n");

    Zunanje* glava = porazdeli(zacetek, 5);

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
