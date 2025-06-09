#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IME_DAT 101
#define MAX_STEVILO 1000000000




int main(){
    int n, x;
    scanf("%d", &n);
    FILE **vhodne = malloc(n*sizeof(FILE*));
    int *stevila = calloc(MAX_STEVILO+1, sizeof(int));
    char bufferVhodov[101];
    char buffer[101];
    for (size_t i = 0; i < n; i++)
    {
        scanf("%s", bufferVhodov);
        vhodne[i] = fopen(bufferVhodov, "r");
        while (fgets(buffer, sizeof(buffer), vhodne[i]) != NULL) {
            sscanf(buffer, "%d", &x);
            stevila[x]++;
            // printf("%d = [%d]\n", x, stevila[x]);
            if(x > stevila[0]) stevila[0] = x;
        }
        
    }
    
    scanf("%s", buffer);
    FILE *izhodna = fopen(buffer, "w");
    for (int i = 1; i <= stevila[0]; i++)
    {
        while(stevila[i] != 0) {
            fprintf(izhodna, "%d\n", i);
            stevila[i]--;
        }
    }
    
    
    // printf("0 = %d\n", stevila[0]);







    return 0;
}