
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga2.c
./a.out

Samodejno testiranje:

export name=naloga2
make test

Testni primeri:

test01: primer iz besedila
test02..test07: ro"cno izdelani kratki testi
test08..test09: samodejno izdelani, n = 1
test10..test17: samodejno izdelani, n > 1

.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in izpi"se rezultat)
.dat: testni podatki
.out: pri"cakovani izhod
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "naloga2.h"

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

Vozlisce** tabelaSeznamov(int* t, int d, int n) {
    Vozlisce **rezultat = (Vozlisce**) calloc(n, sizeof(Vozlisce *));
    int x, inc, index;
    for (int i = 0; i < n; i++)
    {
        inc = 1<<i; //1, 2, 4, 8
        x = d / inc; //10, 5, 2, 1
        
        rezultat[i] = (Vozlisce*) calloc(x, sizeof(Vozlisce));

        index = -1 + inc; //0, 1, 3, 7 

        for (size_t j = 0; j < x; j++)
        {
            rezultat[i][j].vTabelo = &t[index];
            if(j < x-1) rezultat[i][j].naslednje = &rezultat[i][j+1];
            else rezultat[i][j].naslednje = NULL;
            index += inc;
            
        }
        
    }


    return rezultat;  
}



Vozlisce** tabelaSeznamovZupi(int* t, int d, int n) {
    Vozlisce ** start = (Vozlisce**) malloc(n * sizeof(Vozlisce *));

    for(int i = 0; i < n; i++) start[i] = (Vozlisce*) malloc(n * sizeof(Vozlisce));

    Vozlisce** list = start;

    for(int i = 0; i < n; i++) {
        Vozlisce *curr = list[i];

        for(int ind = (1 << i) -1; ind < d; ind += (1 << i)) {
            curr->vTabelo = &t[ind];
            if(ind + (1 << i) < d){
                curr->naslednje = (Vozlisce*) malloc(n * sizeof(Vozlisce));
            } else curr->naslednje = NULL;
            curr = curr->naslednje;
        }
    }
    return start;
}







//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    // Tole dopolnite, "ce "zelite funkcijo testirati s svojimi lastnimi
    // podatki.
    return 0;
}

#endif
