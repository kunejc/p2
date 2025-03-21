#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d",&n);
    int tab[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tab[i]);
    }

    int maxSum = INT_MIN;
    int sumI = 0;

    for (int  i = 0; i < n; i++)
    {
        sumI += tab[i];
        if(sumI > maxSum) maxSum = sumI;
        if (sumI < 0) sumI = 0;
        

        // for (int j = i; j < n; j++)
        // {
        //     if(sumI > maxSum) maxSum = sumI;
        // }
        
    }
    printf("%d\n", maxSum);





    return 0;
}