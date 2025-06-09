#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

#include "naloga.h"

int steviloZnakov(char* niz, char znak) {
    if (*niz == '\0') return 0;
    return (*niz == znak) + steviloZnakov(niz+1, znak);
}

char* kopirajDoZnaka(char* niz, char znak) {
    char *izhod = niz;
    while(*niz != znak && *niz != '\0') niz++;
    *niz = '\0';
    return izhod;

}

char** razcleni(char* niz, char locilo, int* stOdsekov) {
    char* niz2 = malloc(strlen(niz) + 1);
    strcpy(niz2, niz);
    *stOdsekov = steviloZnakov(niz2, locilo) + 1;
    char **izhod = (char**) malloc(*(stOdsekov) * sizeof(char*));
    
    for (size_t i = 0; i < *stOdsekov; i++)
    {
        izhod[i] = kopirajDoZnaka(niz2, locilo);
        niz2 += strlen(izhod[i]) +1;
    }
    return izhod;
}

#ifndef test

int main() {

    // Example with a modifiable buffer (works)
    char *seznam = malloc(12 * sizeof(char));
    char elementi[] = {'a', 'b', 'a', 'g', 'b', 'a', 'a', 'b', 'c', 'a', 'a'};
    memcpy(seznam, elementi, 11 * sizeof(char));

    int stOdsekov;
    char* niz = seznam;
    char** odseki = razcleni(niz, 'b', &stOdsekov);

    printf("Stevilo odsekov: %d/%ld\n", stOdsekov, strlen(seznam));
    for (int i = 0; i < stOdsekov; i++) {
        printf("Odsek %d: \"%s\"\n", i, odseki[i]);
    }
    free(odseki);
    free(seznam);

    // Example with a string literal (will crash!)
    char *literal = "abagbaabcaa";
    int stOdsekovLit;
    // This will likely cause a segmentation fault:
    char **odsekiLit = razcleni(literal, 'b', &stOdsekovLit);

    printf("Stevilo odsekov (literal): %d/%ld\n", stOdsekovLit, strlen(literal));
    for (int i = 0; i < stOdsekovLit; i++) {
        printf("Odsek %d: \"%s\"\n", i, odsekiLit[i]);
    }
    free(odsekiLit);

    return 0;

}

#endif
