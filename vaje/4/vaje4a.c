#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);
    int tab[n];
    int flag = 0;

    for (int i = 0; i < n; i++) {
        tab[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int inp;
        scanf("%d", &inp);
        if(inp > n){
            printf("NE\n");
            flag = 1;
        } 
        else {
            tab[inp] = 1;       
        } 
    }

    if(!flag) {
        for (int i = 0; i < n; i++)
        {
            if(!tab[i]){
                printf("NE\n");
                flag = 1;
                break;
            }       
        }

    }
    if(!flag) printf("DA\n");
    
    






    return 0;
}