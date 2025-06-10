
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga1.c
./a.out

Samodejno testiranje:

export name=naloga1
make test

Testni primeri:

test01: primer iz besedila
test02..test08: ro"cno izdelani kratki testi
test09..test11: samodejno izdelani, tip Exxx_Exxx_Exxx_...
test12..test14: samodejno izdelani, vsakemu E-ju sledi "stevilo iz [100, 999]
test15..test17: samodejno izdelani, splo"sni

.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in izpi"se rezultat)
.dat: testni podatki
.out: pri"cakovani izhod
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

int sestEj(char* niz) {
    char *cur = niz;    
    char *buff = malloc(10*sizeof(char));
    int x;
    int sum = 0;

    while(*cur != '\0') {
        if(*cur == 'E')
        {
            cur++;
            if (*cur>= '1' && *cur<='9')
            {
                buff[0] = *cur;
                cur++;
                if (*cur>='0' && *cur<='9')
                {
                    buff[1] = *cur;
                    cur++;
                    if (*cur>='0' && *cur<='9')
                    {
                        buff[2] = *cur;
                        cur++;
                        if(*cur == '_') {
                            buff[3] = *cur;
                            cur++;
                            sscanf(buff, "%d", &x);
                            sum += x;
                        }
                        
                    }
                    
                }
                    
            }
                
        }
    else cur++;



    }
    return sum;
}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    
    // char* test = "543_E123_e456_E75_E900/E7.4_E825.3_E0357_E089_E_EE651_abcdE736_E842";
    // printf("vsota: %d", sestEj(test));


    return 0;
}

#endif
