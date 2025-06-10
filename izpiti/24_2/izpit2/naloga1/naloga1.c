
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 *
 * Javni testni primeri:
 *
 * 02..06: v vsakem podprimeru je "stevilo nizov enako 42
 * 01, 07..10: splo"sni primeri
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>



// po potrebi dopolnite ...

int jeVeljavna(char* vrstica, int n) {
    int premikX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int premikY[] = {1, -1, 2, -2, 2, -2, -1, 1};
    bool* premiki = calloc(8, sizeof(bool));

    while (strlen(vrstica) >= 5)
    {
        int x1 = *(vrstica) - 'a';
        int y1 = *(vrstica+1) - '1';
        int x2 = *(vrstica+3) - 'a';
        int y2 = *(vrstica+4) - '1';

        int pX = x2-x1;
        int pY = y2-y1;


        if (abs(pX * pY) != 2) return 0;

        for (int i = 0; i < 8; i++)
        {
            if (premikX[i] == pX && premikY[i] == pY)
            {
                premiki[i] = true;
            }
        }
        vrstica += 3;
    }
    for (int i = 0; i < 8; i++)
    {
        if (!premiki[i]) return 0;        
    }   
    

    return 1;
}

int main(int argc, char** argv) {
    FILE* vhodna = fopen(argv[1], "r");
    FILE* izhodna = fopen(argv[2], "w");

    int n, stVrstic;
    char* vrstica = calloc(310, sizeof(char));

    fscanf(vhodna, "%d %d\n", &n, &stVrstic);

    for (int i = 0; i < stVrstic; i++)
    {
        fgets(vrstica, 310, vhodna);
        fprintf(izhodna, "%d\n", jeVeljavna(vrstica, n));
    }
       
    return 0;
}
