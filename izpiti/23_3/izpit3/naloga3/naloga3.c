
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Javni testni primeri:
 *
 * 01: iz besedila naloge
 * 02..04: znaki v nizu so padajo"ce urejeni
 * 01, 05..10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

char najdiMaxChar(char *buffer){
    char max = 0;
    for (size_t i = 0; i < strlen(buffer); i++)
    {
        if(buffer[i] > max) max = buffer[i];
    }
    return max;
}

void razbij(char *buffer, char max) {
    if(strlen(buffer) == 0);
    else if (strlen(buffer) == 1) printf("%s\n", buffer);
    else {
        char *trenuten = buffer;
        while (*trenuten != max) trenuten++;
        int index = trenuten - buffer;
        char *buff1 = malloc(200*sizeof(char));
        char *buff2 = malloc(200*sizeof(char));

        for (size_t i = 0; i < index; i++)
        {
            buff1[i] = buffer[i];
        }
        buff1[index] = '\0';
        
        for (size_t i = index+1; i < strlen(buffer); i++)
        {
            buff2[i] = buffer[i];
        }
        buff2[strlen(buffer)] = '\0';

        printf("%s\n", buff1);       
        razbij(buff1, max);

        printf("%c\n", max);       
        razbij(&max, max);

        printf("%s\n", buff1);       
        razbij(buff2, max);
         



    }





}





int main() {
    char buffer[200];
    scanf("%s", buffer);
    char max = najdiMaxChar(buffer);
    razbij(buffer, max);
    return 0;
}
