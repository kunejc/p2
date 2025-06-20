
/*
 * Zagon posami"cnega primera:
 *
 * gcc naloga2.c
 * ./a.out < test01.in
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 *
 * Javni testni primeri:
 * 02--04: h = 1
 * 01, 05--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

int main() {
    char imeDatoteke[40];
    int h, w, n;
    scanf("%s %d %d %d", imeDatoteke, &h, &w, &n);
    int steviloByteov = (h * w)/8;

    FILE *vhodna = fopen(imeDatoteke, "rb");
    uint8_t buffer = 0;
    int *matrika = calloc(h*w, sizeof(int));

    for (size_t i = 0; i < steviloByteov; i++)
    {
        fread(&buffer, sizeof(uint8_t), 1, vhodna);
        matrika[0+i*8] = (buffer >> 7) & 1;
        matrika[1+i*8] = (buffer >> 6) & 1;
        matrika[2+i*8] = (buffer & 32) ? 1 : 0;
        matrika[3+i*8] = (buffer & 16) ? 1 : 0;
        matrika[4+i*8] = (buffer & 8) ? 1 : 0;
        matrika[5+i*8] = (buffer & 4) ? 1 : 0;
        matrika[6+i*8] = (buffer & 2) ? 1 : 0;
        matrika[7+i*8] = (buffer & 1) ? 1 : 0;
    }

    int a, b, c;
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        c = (a * w) + b; 
        printf("%d\n", matrika[c]);
    }
    




    return 0;
}
