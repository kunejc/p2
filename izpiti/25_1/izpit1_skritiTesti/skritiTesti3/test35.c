
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

int TABELA[] = {5112, 4057, 7681, 3944, 7788, 6662, 9714, 2763, 2472, 8400, 2367, 4302, 347, 1366, 3089, 5119, 6667, 6957, 712, 2169, 764, 6154, 2938, 3438, 4878, 3576, 1766, 9565, 6033, 8394, 1425, 9448, 1150, 3213, 8159, 4350, 6436, 4832, 4739, 8870, 9359, 1114, 927, 4462, 6972, 8699, 3099, 7161, 3846, 9475, 1204, 1328, 9723, 5051, 2222, 1230, 3577, 3087, 2723, 839, 9837, 3528, 9741, 1353, 9845, 999, 6445, 8765, 2336, 9327, 1487, 1265, 8735, 5407, 2329, 8558, 1866, 7649, 1179, 4311, 7397, 6630, 3948, 848, 6552, 7609, 803, 5662, 5629, 4559, 9659, 1135, 5839, 7569, 2689, 8921, 2212, 5742, 3230, 3021, 7814, 7644, 7355, 5327, 2279, 8793, 4410, 5618, 4786, 8739, 2860, 1092, 6198, 5115, 9738, 3084, 2482, 5539, 1280, 1087, 5516, 8384, 6798, 3384, 6351, 680, 9766, 7106, 3435, 6761, 9379, 8904, 9892, 4638, 4324, 2757, 5265, 8608, 8010, 1604, 81, 3950, 4211, 3852, 4144, 6049, 4105, 1566, 8279, 6416, 1417, 5999, 3677, 9958, 1430, 4224, 4984, 46, 8231, 688, 281, 9324, 1193, 7827, 1300, 1450, 9118, 9575, 1158, 4944, 2458, 6592, 2214, 9750, 562, 4472, 1805, 5888, 2280, 906, 8346, 9840, 2617, 1909, 1912, 8025, 726, 3344, 1149, 2464, 2349, 7306, 9681, 8607, 8373, 9233, 744, 7633, 7916, 8473, 2396, 5838, 6680, 2345, 888, 1377, 5050, 6083, 8084, 6260, 7632, 1953, 7861, 4860, 2517, 789, 3342, 4783, 7562, 7486, 6142, 8915, 6746, 9507, 1198, 7280, 5659, 5041, 8604, 4580, 9095, 6666, 1568, 2840, 1620, 5499, 4779, 4018, 594, 9433, 4850, 2004, 1514, 556, 4981, 2545, 596, 3894, 7142, 3511, 8248, 5645, 7990, 4772, 3104, 2361, 123, 9793, 7297, 0, 8736, 424, 5738, 2525, 1966, 728, 1741, 2186, 380, 1795, 7597, 1699, 7983, 2594, 7078, 5391, 2553, 6453, 1621, 7246, 8320, 2872, 5500, 2023, 441, 6893, 3863, 279, 7454, 3805, 2939, 4212, 8043, 9791, 8208, 8094, 2301, 7356, 7086, 6618, 6797, 9321, 3469, 4255, 5523, 9311, 4650, 2562, 9076, 8260, 3503, 625, 7489, 9148, 8660, 7302, 5544, 1667, 7283, 4659, 8440, 9347, 7735, 8291, 1572, 589, 8901, 6529, 3796, 4257, 5255, 5444, 1402, 4359, 5533, 3316, 5897, 8417, 1765, 1259, 4916, 8371, 8052, 7507, 981, 9098, 3883, 3700, 2093, 1968, 9504, 2045, 3111, 4137, 6347, 6185, 210, 9473, 4640, 2907, 2161, 5238, 5574, 8430, 5282, 677, 2794, 9153, 7112, 6310, 964, 4754, 1599, 3627, 466, 1020, 3289, 3780, 959, 7163, 6307, 3565, 6253, 1269, 3234, 349, 3133, 6996, 1470, 8007, 2431, 1385, 3179, 7294, 4131, 4717, 5205, 1318, 3923, 1706, 3023, 6771, 7978, 7070, 2056, 3628, 5734, 2820, 657, 7358, 3920, 5545, 287, 1365, 5741, 3829, 735, 1562, 2891, 2655, 3875, 900, 4200, 2541, 9789, 7144, 6686, 2372, 2675, 5347, 8198, 5584, 9062, 9708, 3509, 3535, 4391, 6479, 3268, 1029, 8711, 5798, 2590, 3504, 4151, 1327, 9887, 3722, 1610, 85, 2621, 379, 6597, 9925, 8466, 3683, 8295, 1201, 6069, 2312, 3726, 1579, 7587, 2504, 2406, 2408, 7535, 6557, 3553, 4902, 3024, 9020, 5011, 23, 3254, 9696, 8669, 2913, 2340, 9983, 7428, 7553, 9265, 7901, 1335, 4120, 1154, 9656, 7179, 9711, 3206, 4068, 241, 2047, 7327, 8789, 6487, 3129, 3946, 145, 1212, 6642, 9373, 6211, 1352, 1249, 5892, 3131, 8971, 5549, 2605, 836, 8806, 7809, 9380, 359, 6758, 815, 9476, 1330, 5753, 3339, 4498, 1187, 5200, 9200, 107, 8364, 9965, 7830, 9330, 2370, 4576, 1360, 6035, 9796, 1061, 1848, 5439, 3641, 1173, 6291, 9578, 2582, 6976, 4950, 9270, 9057, 2292, 9990, 9011, 9479, 9365, 773, 4908, 49, 6755, 4180, 2265, 9664, 8356, 9918, 9778, 5702, 6121, 6297, 912, 7260, 9946, 6567, 5583, 8475, 1704, 2251, 3881, 2846, 5252, 3791, 8724, 9755, 4742, 288, 317, 6078, 805, 9592, 5389, 9788, 132, 2435, 244, 470, 5037, 8527, 7541, 9987, 6688, 3399, 3416, 7638, 2006, 2895, 7221, 1322, 416, 9029, 9929, 5494, 6646, 4183, 7926, 4725, 7863, 2842, 9919, 4843, 8909, 7182, 343, 5053, 2042, 2941, 7174, 9792, 3597, 493, 1275, 47, 9163, 1049, 8425, 4334, 5478, 8795, 8044, 4293, 672, 5946, 3519, 7938, 9335, 364, 7533, 3717, 9349, 5210, 9320, 2544, 2499, 1069, 5301, 15, 5878, 9615, 292, 3921, 9868, 2980, 7035, 4171, 9487, 3323, 7448, 6949, 950, 6034, 8619, 5696, 5287, 8591, 8740, 8199, 2286, 3101, 6858, 1346, 768, 5886, 8075, 8786, 7565, 3371, 7150, 7550, 1988, 4558, 1567, 5505, 7151, 8156, 7694, 7582, 8732, 2413, 1432, 6548, 5867, 7201, 5707, 2746, 8465, 8963, 7613, 2789, 5154, 2120, 6015, 4837, 4037, 4159, 8036, 9560, 4874, 8521, 3448, 4630, 8108, 7423, 5183, 5876, 5223, 4673, 5081, 485, 6892, 2885, 5235, 9733, 5447, 2636, 6527, 5961, 4314, 5047, 4696, 502, 6995, 8577, 1606, 2676, 8819, 3594, 6107, 9063, 3460, 5016, 4951, 8418, 9258, 8144, 4308, 200, 7850, 6141, 4529, 2967, 7424, 2378, 5724, 6743, 9415, 6722, 1206, 5090, 6039, 1537, 1164, 3580, 6498, 8162, 8661, 1746, 1527, 2205, 849, 9834, 5320, 3750, 8889, 8548, 8650, 8059, 2808, 931, 8310, 7027, 655, 4877, 3787, 6387, 3281, 7656, 1718, 1891, 9814, 8189, 7942, 6136, 6170, 9079, 8218, 8690, 4394, 8469, 9785, 9552, 5506, 686, 2782, 5365, 2092, 7950, 9139, 3728, 5221, 7303, 1221, 5473};

int main() {
    int n = sizeof(TABELA) / sizeof(int);
    int najElement = maksimum(TABELA, n);
    Notranje** element2naslov = calloc(najElement + 1, sizeof(Notranje*));

    Notranje* zacetek = zgradi(TABELA, n, element2naslov);

    printf("Vhod: ");
    izpisiNotranje(zacetek);
    printf("\n");

    Zunanje* glava = porazdeli(zacetek, 98);

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
