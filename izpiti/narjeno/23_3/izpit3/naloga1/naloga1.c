
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 *
 * Javni testni primeri:
 *
 * 01: iz besedila naloge
 * 02..04: a = b > 0
 * 05..07: a > b > 0
 * 01, 08..10: ni dodatnih omejitev glede a in b
 * 02, 04, 06, 08, 10: vsak bajt je bodisi 0 bodisi 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    FILE *vhodna1 = fopen(argv[1], "rb");
    FILE *vhodna2 = fopen(argv[2], "rb");
    FILE *izhodna = fopen(argv[3], "wb");

    uint8_t buff1, buff2, buffer;
    while(1) {
        
        if (fread(&buff1, sizeof(uint8_t), 1, vhodna1) == 0)
        {
            while (fread(&buff2, sizeof(uint8_t), 1, vhodna2))
            {
                fwrite(&buff2, sizeof(uint8_t), 1, izhodna);                
            }  
            break;        
        }
        if (fread(&buff2, sizeof(uint8_t), 1, vhodna2) == 0)
        {
            fwrite(&buff1, sizeof(uint8_t), 1, izhodna);                
            while (fread(&buff1, sizeof(uint8_t), 1, vhodna1))
            {
                fwrite(&buff1, sizeof(uint8_t), 1, izhodna);                
            }          
            break;        
        }   
        buffer = (buff1 > buff2) ? buff1 : buff2;
        fwrite(&buffer, sizeof(uint8_t), 1, izhodna);
        
    }
    fclose(vhodna1);
    fclose(vhodna2);
    fclose(izhodna);
    









    return 0;
}
