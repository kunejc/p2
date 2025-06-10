
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -D=test testXY.c naloga2.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 *
 * Javni testni primeri:
 *
 * 01..03: n = 3, d = 1
 * 04..06: d = 1
 * 07..10: splo"sni
 * 01, 04, 07: majhni, ro"cno izdelani primeri
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#include "naloga2.h"

int okoli(int **slika, int x, int y, int d) {
    int minX = x - d;
    int maxX = x + d;
    int minY = y - d;
    int maxY = y + d;
    int sum = 0;


    for(int i = minX; i <= maxX; i++) {
        for(int j = minY; j <= maxY; j++) {
            sum += slika[i][j];
        }
    }
    return sum;


}

int** zmehcaj(int** slika, int n, int m, int d) {
    int nn = n - 2*d;
    int mm = m - 2*d;
    int **nova = malloc(nn*sizeof(int*));
    for (size_t i = 0; i < nn; i++)
    {
        nova[i] = malloc(mm*sizeof(int));
    }
    for (size_t i = 0; i < nn; i++)
    {
        for (size_t j = 0; j < mm; j++)
        {
            nova[i][j] = (okoli(slika, i+d, j+d, d))/((2*d+1)*(2*d+1));
        }
        
    }
    
    return nova;
}

#ifndef test

int main() {
    // "Ce "zelite funkcijo <jeDrevo> testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga2.c).
    return 0;
}

#endif
