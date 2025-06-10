
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

int jeVeljavno(char* vrstica) {
    
    int potezeX[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int potezeY[] = {2, -2, 2, -2, 1, -1, 1, -1,};
    int* poteze = calloc(8, sizeof(int));



    while (strlen(vrstica) >= 5)
    {

        int x1 = *vrstica;
        int y1 = *(vrstica+1);
        int x2 = *(vrstica+3);
        int y2 = *(vrstica+4);

        if (abs(x2 - x1) * abs(y2 - y1) != 2) {
            // printf("Napacna poteza");
            return 0;
        }
        
        for (int i = 0; i < sizeof(poteze); i++)
        {
            if (potezeX[i] == (x2 - x1) && potezeY[i] == (y2 - y1)) {
                poteze[i] = 1;
                
            }
        }
        vrstica +=3;    
    }
    for (int i = 0; i < sizeof(poteze); i++)
    {
        if (poteze[i] == 0){
            
            // printf("BREAK");       
            return 0;
        }  
        // printf("%d", poteze[i]);       
    }
    // printf("");
    return 1;
}

int main(int argc, char** argv) {
    FILE* vhodna = fopen(argv[1], "r");
    FILE* izhodna = fopen(argv[2], "w");


    int n, stVrstic;
    fscanf(vhodna,"%d %d\n", &n, &stVrstic);
    char* vrstica = calloc(320, sizeof(char));
    int veljavno;
    for (int i = 0; i < stVrstic; i++)
    {
        fgets(vrstica, 320, vhodna);
        veljavno = jeVeljavno(vrstica);
        fprintf(izhodna, "%d\n", veljavno);
        // printf("---%d\n", veljavno);
    }
    
    return 0;
}
