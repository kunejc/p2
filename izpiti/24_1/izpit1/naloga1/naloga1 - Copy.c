
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 *
 * Javni testni primeri:
 * 02..06: v vsakem podprimeru je "stevilo polj enako n^2
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int jeVeljavno(char* vrstica, int n) {
    int** polje = calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        polje[i] = calloc(n, sizeof(int));
    }
    int counter = 1;
    bool prvic = true;

    while (strlen(vrstica) >= 5)
    {   
        int x1 = *vrstica - 'a';        
        int y1 = *(vrstica+1) - '1';        
        int x2 = *(vrstica+3) -'a';        
        int y2 = *(vrstica+4) - '1';

        // printf("\033[96m%d ", y1);

        if (abs(x1 - x2) * abs(y1 - y2) != 2) return 0;
               
        if (prvic) polje[x1][y1] = 1;
        
        if (polje[x2][y2] == 0)
        {
            counter++;
            polje[x2][y2] = 1;
        }
        else return 0;

        vrstica += 3;
    }
    if (counter != n*n) 
        return 0;
    
    return 1;
}

int main(int argc, char** argv) {
    FILE* vhodna = fopen(argv[1], "r");
    FILE* izhodna = fopen(argv[2], "w");

    int n, stVrstic;

    fscanf(vhodna, "%d %d\n", &n, &stVrstic);

    char* vrstica = calloc(500, sizeof(char));
    int* izhodi = calloc(stVrstic, sizeof(int));

    for (int i = 0; i < stVrstic; i++)
    {
        fgets(vrstica, 500, vhodna);
        izhodi[i] = jeVeljavno(vrstica, n);
    }
    for (int i = 0; i < stVrstic; i++)
    {
        fprintf(izhodna, "%d\n", izhodi[i]);
    }
    
    





    return 0;
}
