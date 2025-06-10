#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

 Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina) {
    Vozlisce* list = start;
    int index = 0;

    while(index < (mesto -1) && list != NULL) {
        list = list->desno;
        index++;
    }

    Vozlisce *prev = list;
    Vozlisce* new = (Vozlisce*) malloc(sizeof(Vozlisce));

    if(mesto == 0) start = new; 

    int counter = 0;

    while(prev != NULL) {

        if(mesto == 0) {
            new->desno = prev;
        } else {
            new->desno = prev->desno;
            prev->desno = new;
        }
        new->vsebina = vsebina + counter;
        
        if(prev->dol == NULL) {
            new->dol = NULL;
        } else {
            Vozlisce *next_down = (Vozlisce*) malloc(sizeof(Vozlisce));
            new->dol = next_down;
        }

        counter++;
        new = new->dol;
        prev = prev->dol;
    }
    return start;
}

#ifndef test

int main() {

    return 0;
}

#endif