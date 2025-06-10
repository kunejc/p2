
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
// #include <math.h>

int jeVeljavno(char* buffer, int n) {

    bool** polja = calloc(n, sizeof(bool*));
    for (int i = 0; i < n; i++)
    {
        polja[i] = calloc(n, sizeof(bool));
    }
    
    int x1, x2, y1, y2, Dx, Dy;
    while (strlen(buffer) >= 5)
    {
        x1 = *(buffer) -'a';
        y1 = *(buffer +1) -'1';
        x2 = *(buffer +3) -'a';
        y2 = *(buffer +4) -'1';

        Dx = x1-x2;
        Dy = y1-y2;

        if (abs(Dx)*abs(Dy) != 2) return 0;

        polja[x1][y1] = true;
        
        buffer += 3;
        
    }
    polja[x2][y2] = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!polja[i][j]) return 0;            
        }   
    }
    return 1;
}



int main(int argc, char** argv) {

    FILE* vhodna = fopen(argv[1], "r");
    FILE* izhodna = fopen(argv[2], "w");

    int n, stVrstic;

    fscanf(vhodna, "%d %d\n", &n, &stVrstic);
    char* buffer = calloc(1000, sizeof(int));

    for (int i = 0; i < stVrstic; i++)
    {
        fgets(buffer, 1000, vhodna);
        fprintf(izhodna, "%d\n", jeVeljavno(buffer, n));
    }
    return 0;
}
