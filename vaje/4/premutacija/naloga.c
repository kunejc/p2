#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

int main() {

    int n, x, flag = 0;
    scanf("%d", &n);
    int *tabela = calloc(n, sizeof(int));

    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (tabela[x] != 0 && x<n) {
            flag = 1;
            break;
        }
        else tabela[x] = 1;
        
    }
    for (size_t i = 0; i < n; i++)
    {
        if (tabela[i] != 1)
        {
            flag = 1;
            break;       
        }
    }
    if(flag) printf("NE\n");
    else printf("DA\n");
    













    return 0;
}