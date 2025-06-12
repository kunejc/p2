
/*
 * Zagon posami"cnega primera:
 *
 * gcc naloga1.c
 * ./a.out $(cat test01.param)
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 *
 * Javni testni primeri:
 * 02--04: vsa stikala so prve oblike
 * 05--07: vsa stikala so druge oblike
 * 01, 08--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* spremeni(char *niz, int n){
    return niz += n;


}



int main(int argc, char** argv) {
    for (size_t i = 1; i < argc; i++)
    {
        if (argv[i][1] != '-')
        {   
            printf("%s ", spremeni(argv[i], 1));
            i++;
            printf("%s\n", argv[i]);
            
        }
        else {
            printf("%s ", spremeni(argv[i], 2));
            printf("True\n");
            
        }
        
    }

    return 0;
}
