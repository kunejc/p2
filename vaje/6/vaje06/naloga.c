
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// #include <strlen.h>

#include "naloga.h"

int steviloZnakov(char* niz, char znak) {
    int count = 0;
    while(*niz != '\0') {
        if(*niz == znak) count++;
        niz++;
    }
    return count;
}

char* kopirajDoZnaka(char* niz, char znak) {
    int count = 0;
    while(*niz != znak && *niz != '\0') {
        count++;
        niz++;
    }
    niz -= count;
    char *kopija = malloc((count+1)*sizeof(char));
    for (int i = 0; i < count; i++)
    {
        kopija[i] = niz[i];
        
    }
    kopija[count] = '\0';
    
    return kopija;
}

char** razcleni(char* niz, char locilo, int* stOdsekov) {
    int stZnakov = steviloZnakov(niz, locilo);
    *stOdsekov = stZnakov+1;
    
    char** odseki = malloc((*stOdsekov) * sizeof(char*));

    for (int i = 0; i < *stOdsekov; i++)    {
        odseki[i] = kopirajDoZnaka(niz, locilo);
        niz += strlen(odseki[i])+1;
    
    }
    
    return odseki;
}

#ifndef test

int main() {
    // char seznam[] = {'a', 'b', 'a', 'g', 'a', 'a', 'a', 'b', 'c', 'a', 'a'};
    // printf("%d\n", steviloZnakov(seznam, 'b'));

    // char *kopija = kopirajDoZnaka(seznam, 'c');
    // while (*kopija != '\0') {
    //     printf("%c ", *kopija);
    //     kopija++;
    // }
    return 0;
}

#endif
