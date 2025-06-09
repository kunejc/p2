#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IME_DAT 101
#define MAX_STEVILO 1000000000




int main(){
    int stDatotek;
    scanf("%d", &stDatotek);

    int *stevila = calloc(MAX_STEVILO, sizeof(int));

    char bufferIme[MAX_IME_DAT];
    int  bufferStevilo;
    


    for (size_t i = 0; i < stDatotek; i++)
    {
        scanf("%s", bufferIme);
        FILE *datoteka = fopen(bufferIme, "r");
        
        while (fscanf(datoteka, "%d", &bufferStevilo) != EOF)
        {
            if(bufferStevilo > stevila[0]) stevila[0] = bufferStevilo;
            stevila[bufferStevilo]++;
        }
        
        
        fclose(datoteka);            
    }
    
    
    scanf("%s", bufferIme);
    FILE *izhodnaDatoteka = fopen(bufferIme, "w");

    for (int i = 1; i <= stevila[0]; i++)
    {
        while (stevila[i]!=0)
        {
            stevila[i]--;
            fprintf(izhodnaDatoteka, "%d\n", i);
        }
    }
    
    fclose(izhodnaDatoteka);















    return 0;
}