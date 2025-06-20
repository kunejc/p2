
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "dvonivojskaKonstrukcija.h"

int ustvariNotranje(Zunanje *start, int vsebina) {
    Notranje *novo = calloc(1, sizeof(Notranje));
    novo->podatek = vsebina;

    if (start->zadnje == NULL)
    {
        start->prvo = novo;
        start->zadnje = novo;
    }
    else {
        start->zadnje->desno = novo;
        start->zadnje = novo;
    }
    return 1;
}




Zunanje* izdelajDvonivojsko(int* t, int n) {
    if(n==0) return NULL;
    
    Zunanje *rez = calloc(1, sizeof(Zunanje));
    
    Zunanje *trenutno = rez;    
    int narejeno = 0;

    for (size_t i = 0; i < n; i++)
    {
        narejeno = 0;
        trenutno = rez;
        while (!narejeno)
        {
            if (trenutno->zadnje == NULL) {
                narejeno = ustvariNotranje(trenutno, t[i]);
            }
            else if (trenutno->zadnje->podatek <= t[i]) {
                narejeno = ustvariNotranje(trenutno, t[i]);
            }
            else {
                if(trenutno->dol == NULL) {
                    Zunanje *novo = calloc(1, sizeof(Zunanje));
                    trenutno->dol = novo;
                    trenutno = novo;                   
                }
                else trenutno = trenutno->dol;

            }     
        }
    }
    return rez;
}

#ifndef test

int main() {
    return 0;
}

#endif
