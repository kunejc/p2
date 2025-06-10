
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

int jeVeljavna(char* vrstica, int n) {

    bool** polja = calloc(n, sizeof(bool*));
    for (int i = 0; i < n; i++)
    {
        polja[i] = calloc(n, sizeof(bool));
    }
    
    bool prvic = true;
    int c = 1;


    while (strlen(vrstica) >= 5)
    {
        int x1 = *(vrstica) - 'a';
        int y1 = *(vrstica +1) - '1';
        int x2 = *(vrstica +3) - 'a';
        int y2 = *(vrstica +4) - '1';

        if (prvic) {
            polja[x1][y1] = true;
            prvic = false;
        } 
        if (abs(x2-x1) * abs(y2-y1) != 2)
            return 0;

        if (!polja[x2][y2]) 
        {
            polja[x2][y2] = true;
            c++;
        }
        else return 0; 

        vrstica += 3; 
        
        

    }
    if (c != n*n) return 0;
   
    return 1;
}

int main(int argc, char** argv) {

    FILE* vhodna = fopen(argv[1], "r");
    FILE* izhodna = fopen(argv[2], "w");

    int n, stVrstic;
    char* vrstica = calloc(500, sizeof(char));

    fscanf(vhodna, "%d %d\n", &n, &stVrstic);
    for (int i = 0; i < stVrstic; i++)
    {
        fgets(vrstica, 500, vhodna);
        fprintf(izhodna, "%d\n", jeVeljavna(vrstica, n));
    }
    













    return 0;
}
