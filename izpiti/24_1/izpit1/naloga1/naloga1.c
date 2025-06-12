
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

int jeVeljaven(int x1, int y1, int x2, int y2){
    if(abs(x2-x1)*abs(y2-y1)==2) return 1;
    return 0;
}


int main(int argc, char** argv) {

    FILE *vhodna = fopen(argv[1], "r");
    FILE *izhodna = fopen(argv[2], "w");

    int n, stVrstic;
    scanf("%d %d", &n, &stVrstic);

    int x1, y1, x2, y2, output = 0;
    // int *x = calloc(2*n*n, sizeof(int));
    // int *y = calloc(2*n*n, sizeof(int));


    for (size_t i = 0; i < stVrstic; i++)
    {
        int **zasedeno = calloc(n, sizeof(int));
        for (size_t i = 0; i < n; i++) zasedeno[i] = calloc(n, sizeof(int));
        
        x1 = fgetc(vhodna) - 'a';
        y1 = fgetc(vhodna) - '0';
        fgetc(vhodna);
        zasedeno[x1][y1] = 1;
        
        while (1)
        {
            x2 = fgetc(vhodna);
            y2 = fgetc(vhodna);
            fgetc(vhodna);
            
            if (x2 == EOF) break;

            x2 -= 'a';
            y2 -= '0';

            if (!jeVeljaven(x1, y1, x2, y2) || zasedeno[x2][y2]) output = 0;
            x1 = x2;
            y1 = y2;         
            
        
        
        
        
        
        
        }
        fprintf(izhodna, "%d\n", output);
        free(zasedeno);
    }














    return 0;
}
