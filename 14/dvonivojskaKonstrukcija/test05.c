
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "dvonivojskaKonstrukcija.h"

const char* DATOTEKA = "test05.dat";

int* izdelajTabelo(const char* datoteka, int* stElementov) {
    FILE* f = fopen(datoteka, "r");
    fscanf(f, "%d", stElementov);
    int* t = calloc(*stElementov, sizeof(int));
    for (int i = 0; i < *stElementov; i++) {
        fscanf(f, "%d", &t[i]);
    }
    fclose(f);
    return t;
}

void izpisi(Zunanje* zunanje) {
    if (zunanje == NULL) {
        printf("NULL\n");
        return;
    }

    while (zunanje != NULL) {
        Notranje* v = zunanje->prvo;
        while (v != NULL) {
            if (v != zunanje->prvo) {
                printf(" ");
            }
            printf("%d", v->podatek);
            if (v == zunanje->zadnje) {
                printf("<");
            }
            v = v->desno;
        }
        zunanje = zunanje->dol;
        printf("\n");
    }
}

void pocisti(Zunanje* zunanje) {
    while (zunanje != NULL) {
        Notranje* v = zunanje->prvo;
        while (v != NULL) {
            Notranje* w = v;
            v = v->desno;
            free(w);
        }
        Zunanje* z = zunanje;
        zunanje = zunanje->dol;
        free(z);
    }
}

int main() {
    int n = 0;
    int* t = izdelajTabelo(DATOTEKA, &n);

    Zunanje* zunanje = izdelajDvonivojsko(t, n);

    izpisi(zunanje);
    pocisti(zunanje);

    free(t);

    return 0;
}
