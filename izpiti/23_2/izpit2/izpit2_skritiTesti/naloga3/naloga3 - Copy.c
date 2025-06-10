
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -D=test testXY.c naloga3.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Testni primeri:
 * 02, 03: h = 1
 * 04, 05, 06: preverjajo samo vsoto
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

// po potrebi dopolnite ...

Vozlisce* diagonala(Vozlisce* start, int* vsota) {

    Vozlisce* zacetek = start;
    size_t dolzinaDiagonale = 0;
    size_t sirinaTabele;
    *vsota = 0;

    while (zacetek->desno && zacetek->dol)
    {
        dolzinaDiagonale++;
        zacetek = zacetek->desno;
        zacetek = zacetek->dol;
    }
    sirinaTabele = dolzinaDiagonale;
    while (zacetek->desno)
    {
        sirinaTabele++;
        zacetek = zacetek->desno;
    }
    zacetek = start;
    
    Vozlisce** diagonala = malloc(dolzinaDiagonale * sizeof(Vozlisce*));

    Vozlisce* node = zacetek;

    size_t c = 0;
    while (node->dol && c < sirinaTabele )
    {
        node = node->dol;
    }
    for (size_t i = 0; i < (sirinaTabele - dolzinaDiagonale); i++)
    {
        node = node->desno;
    }

    for (size_t i = 0; i < dolzinaDiagonale; i++)
    {
        diagonala[i] = malloc(sizeof(Vozlisce));
        diagonala[i]->vsebina = node->vsebina;
        *vsota += diagonala[i]->vsebina;
        diagonala[i]->dol = NULL;
        if (i > 0)
        {
            diagonala[i-1]->desno = diagonala[i];
        }
 
        node = node->desno;
        node = node->dol;
        
    }



   return diagonala[0];
}

//=============================================================================

#ifndef test

#define _VISINA 3
#define _SIRINA 4

Vozlisce* _MATRIKA[_VISINA][_SIRINA];

const int _VSEBINA[_VISINA][_SIRINA] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
};

void _napolni() {
    for (int i = 0; i < _VISINA; i++) {
        for (int j = 0; j < _SIRINA; j++) {
            _MATRIKA[i][j] = calloc(1, sizeof(Vozlisce));
            _MATRIKA[i][j]->vsebina = _VSEBINA[i][j];
        }
    }
    for (int i = 0; i < _VISINA; i++) {
        for (int j = 0; j < _SIRINA; j++) {
            if (j < _SIRINA - 1) {
                _MATRIKA[i][j]->desno = _MATRIKA[i][j + 1];
            }
            if (i < _VISINA - 1) {
                _MATRIKA[i][j]->dol = _MATRIKA[i + 1][j];
            }
        }
    }
}

void _izpisiDiagonalo(Vozlisce* v) {
    printf("Diagonala:\n");
    printf("[");
    Vozlisce* w = v;
    while (w != NULL) {
        if (w != v) {
            printf(", ");
        }
        printf("%d", w->vsebina);
        w = w->desno;
    }
    printf("]\n\n");
}

void _izpisiOriginal(Vozlisce* v0) {
    printf("Originalna matrika -- po vrsticah:\n");
    Vozlisce* v = v0;
    int i = 0;
    while (v != NULL) {
        printf("%d: [", i);
        Vozlisce* w = v;
        while (w != NULL) {
            if (w != v) {
                printf(", ");
            }
            printf("%d", w->vsebina);
            w = w->desno;
        }
        printf("]\n");
        v = v->dol;
        i++;
    }

    printf("\n");
    printf("Originalna matrika -- po stolpcih:\n");
    v = v0;
    i = 0;
    while (v != NULL) {
        printf("%d: [", i);
        Vozlisce* w = v;
        while (w != NULL) {
            if (w != v) {
                printf(", ");
            }
            printf("%d", w->vsebina);
            w = w->dol;
        }
        printf("]\n");
        v = v->desno;
        i++;
    }
}

void _pocistiDiagonalo(Vozlisce* v) {
    while (v != NULL) {
        Vozlisce* temp = v->desno;
        free(v);
        v = temp;
    }
}

void _pocistiOriginal(Vozlisce* v0) {
    Vozlisce* v = v0;
    while (v != NULL) {
        Vozlisce* w = v;
        while (w != NULL) {
            Vozlisce* temp = w->desno;
            free(w);
            w = temp;
        }
        v = v->dol;
    }
}

int main() {
    // _napolni();
    // int vsota = 0;
    // Vozlisce* diag = diagonala(_MATRIKA[0][0], &vsota);

    // printf("vsota = %d\n\n", vsota);

    // _izpisiDiagonalo(diag);
    // _izpisiOriginal(_MATRIKA[0][0]);

    // _pocistiDiagonalo(diag);
    // _pocistiOriginal(_MATRIKA[0][0]);

    return 0;
}

#endif
