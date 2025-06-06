#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

#include "naloga.h"

int vsota(int* zac, int* kon) {
    int sum = *zac;
    while (zac != kon)      
    {
        zac++;
        sum += *zac;
    }
    return sum;
}

void indeksInKazalec(int* t, int* index, int** kazalec) {
    if(*index == -1) *index = *kazalec - t;
    else *kazalec = &t[*index];

}

void frekvenceCrk(char* niz, int** frekvence) {
    int *pogostost = malloc(26*sizeof(int));
    *frekvence = pogostost;
    for (size_t i = 0; i < strlen(niz); i++)
    {
        if ((niz[i]>=97 && niz[i]<=122)  ||  (niz[i]>=65 && niz[i]<=90))
        {
            if(niz[i] - 'a' < 0) pogostost[niz[i]-'A']++;
            else pogostost[niz[i]-'a']++;
        }
    } 
    
    




}

#ifndef test

int main() {
    // int seznam[] = {2,3, 1, 1, 1, 1, 2}; //sum = 11
    // printf("sum= %d\n", vsota(seznam, &seznam[1]));


    return 0;
}

#endif
