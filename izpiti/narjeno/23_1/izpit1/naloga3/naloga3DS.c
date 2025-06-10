
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
 * 04, 05, 06: mesto = 0
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

int dobiVisino(Vozlisce *start) {
    int visina = 1;
    Vozlisce *temp = start;
    while (temp->dol != NULL) {
        temp = temp->dol;
        visina++;
    }
    return visina;
}

Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina) {
    int visina = dobiVisino(start);
    Vozlisce **novaVozlisca = malloc(visina * sizeof(Vozlisce*));
    
    for (int i = 0; i < visina; i++) {
        novaVozlisca[i] = malloc(sizeof(Vozlisce));
        novaVozlisca[i]->vsebina = vsebina + i;
        if (i == visina - 1) {
            novaVozlisca[i]->dol = NULL;
        } else {
            novaVozlisca[i]->dol = novaVozlisca[i + 1];
        }
    }

    if (mesto == 0) {
        Vozlisce *trenutno = start;
        for (int i = 0; i < visina; i++) {
            novaVozlisca[i]->desno = trenutno;
            if (i < visina - 1) {
                trenutno = trenutno->dol;
            }
        }
        Vozlisce *result = novaVozlisca[0];
        free(novaVozlisca);
        return result;
    } else {
        Vozlisce *current_left = start;
        for (int j = 0; j < mesto - 1; j++) {
            current_left = current_left->desno;
        }

        for (int i = 0; i < visina; i++) {
            Vozlisce *desni = current_left->desno;
            current_left->desno = novaVozlisca[i];
            novaVozlisca[i]->desno = desni;

            if (i < visina - 1) {
                current_left = current_left->dol;
            }
        }
        free(novaVozlisca);
        return start;
    }
}

//=============================================================================

#ifndef test

int main() {
    
    return 0;
}

#endif
