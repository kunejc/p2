
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int vsota(int* zac, int* kon) {
    int sum = 0;
    while (zac!=kon) {
        sum += *zac;
        zac++;
    }
    sum += *zac;
    

    return sum;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {
    if(*indeks == -1) *indeks = *kazalec-t;
    else *kazalec = &t[*indeks];


}

void frekvenceCrk(char* niz, int** frekvence) {
    // char a = 'Z'; // 97a - 122z, 65A-90Z

    *frekvence = calloc(26, sizeof(int));


    while(*niz != '\0') {
        if (*niz < 95){
            (*frekvence)[*niz-'A']++;
        }
        else (*frekvence)[*niz-'a']++;
        
        niz++;
    }
    
}

#ifndef test

int main() {
    // int seznam[] = {2,3, 1, 1, 1, 1, 2}; //sum = 11
    // printf("sum= %d\n", vsota(seznam, &seznam[5]));


    return 0;
}

#endif
