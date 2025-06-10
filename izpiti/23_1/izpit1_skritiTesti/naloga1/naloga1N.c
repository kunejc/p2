
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>


// po potrebi dopolnite ...

int main(int argc, char** argv) {

    FILE *vhodna = fopen(argv[1], "rb");
    FILE *izhodna = fopen(argv[2], "wb");

    uint8_t buff1[1];
    uint8_t buff2[1];

    while (fread(buff1, sizeof(uint8_t), 1, vhodna))
    {
        if (*buff1 == 0x1b)
        {
            if(fread(buff2, sizeof(uint8_t), 1, vhodna)) 
            {
                if(*buff2 == 0xc9) {
                fwrite(buff2, sizeof(uint8_t), 1, izhodna);
                }
                {
                    fwrite(buff1, sizeof(uint8_t), 1, izhodna);
                    fwrite(buff2, sizeof(uint8_t), 1, izhodna);
                }
            }
            else {
                fwrite(buff1, sizeof(uint8_t), 1, izhodna);
                break;
            }
        }
        else {
            fwrite(buff1, sizeof(uint8_t), 1, izhodna);
        }
        
    }
    










    return 0;
}
