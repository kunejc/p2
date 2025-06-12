
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

int TABELA[] = {7176, 8859, 767, 5495, 889, 7374, 6611, 9641, 9479, 6513, 4082, 9721, 7578, 7133, 9363, 2295, 3039, 1297, 303, 560, 5077, 8059, 6452, 168, 8644, 6986, 5211, 9115, 1585, 5372, 8180, 1810, 8216, 6955, 3883, 9855, 2384, 2814, 3853, 6646, 4335, 1268, 3501, 203, 9284, 8151, 9607, 7233, 6792, 629, 7166, 4282, 3060, 1387, 318, 4834, 8266, 3951, 2225, 9125, 8520, 890, 8967, 1256, 2937, 9897, 191, 3491, 6949, 7355, 5005, 9273, 1930, 2302, 9370, 3013, 3530, 5695, 4285, 3331, 9255, 5474, 8525, 8519, 6783, 5972, 5782, 2961, 8372, 5221, 3113, 9167, 8710, 9440, 5169, 7589, 9441, 4780, 375, 4574, 4902, 9480, 9835, 9375, 3650, 6752, 4666, 5224, 7373, 4355, 8547, 5959, 9178, 3621, 9231, 8643, 8973, 2871, 9656, 772, 6957, 1888, 9378, 1000, 1781, 928, 9690, 8285, 384, 7335, 2341, 2502, 5703, 6878, 8573, 5866, 161, 2987, 9688, 8093, 6214, 4601, 8541, 8476, 3863, 7962, 5424, 9765, 7303, 9651, 746, 9739, 3388, 1540, 5968, 9590, 4512, 3148, 4629, 5338, 9420, 8209, 8320, 8104, 1340, 7139, 6208, 5786, 7223, 1813, 4411, 6090, 26, 5835, 4759, 5585, 1845, 3132, 3053, 6594, 5615, 9896, 4900, 4971, 1535, 7400, 5172, 8608, 3552, 4891, 473, 3632, 5709, 6228, 18, 7366, 8251, 279, 3282, 9923, 6805, 3040, 9179, 2334, 1342, 5801, 8168, 9351, 9252, 9013, 8929, 4824, 6962, 8089, 7808, 2239, 9383, 4383, 7596, 9682, 4821, 6463, 6300, 8473, 7209, 9465, 9782, 9877, 1957, 4895, 4450, 3142, 9081, 1333, 1571, 3273, 9800, 6582, 9870, 8852, 4738, 8810, 9028, 3477, 4332, 1730, 6370, 7563, 1871, 3306, 7071, 5978, 6888, 2658, 8129, 4475, 2036, 9890, 5549, 4744, 5014, 5942, 9289, 4628, 5412};

int main() {
    int n = sizeof(TABELA) / sizeof(int);

    Notranje* zacetek = zgradi(TABELA, n);

    printf("Vhod: ");
    izpisiNotranje(zacetek);
    printf("\n");

    Zunanje* glava = porazdeli(zacetek, 22);

    printf("Izhod: ");
    izpisiZunanje(glava);
    printf("\n");

    pocistiZunanje(glava);
    return 0;
}
