
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
    int premikiX[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int premikiY[] = {2, -2, 2, -2, 1, -1, 1, -1}; 
    int* premiki = calloc(8, sizeof(int)); 

    while (strlen(vrstica) >= 5) 
    {
        int x1 = *vrstica;
        int y1 = *(vrstica +1);
        int x2 = *(vrstica +3);
        int y2 = *(vrstica +4);

        
        
        
        if (abs(x2 - x1) * abs(y2 - y1) != 2) return 0;
        for (int i = 0; i < 8; i++)
        {
            if (x2 - x1 == premikiX[i] && y2 - y1 == premikiY[i]) premiki[i] = 1;           
        }


        vrstica += 3;       
    }

    for (int i = 0; i < 8; i++)
    {
        if (premiki[i] == 0) return 0;
    }
    return 1;
}

int main(int argc, char** argv) {

    FILE* vhodniF = fopen(argv[1], "r");
    FILE* izhodniF = fopen(argv[2], "w");

    int velSah, p;
    fscanf(vhodniF, "%d", &velSah);
    fscanf(vhodniF, "%d\n", &p);
    
    char* vrstica = calloc(500, sizeof(char));
    // fgets(vrstica, 320, vhodniF);

    for (int i = 0; i < p; i++)
    {
        fgets(vrstica, 320, vhodniF);
        char* temp = calloc(3500, sizeof(char));
        strcpy(temp, vrstica);
        fprintf(izhodniF, "%d\n", jeVeljavno(vrstica));
    }
    
    // fclose(vhodniF);
    // fclose(izhodniF);
    return 0;
}
