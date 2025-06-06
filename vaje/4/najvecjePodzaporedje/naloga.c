#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

int main() {
    int n, sum, max = INT_MIN;
    scanf("%d", &n);

    int *arr = malloc(n*sizeof(int));

    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (size_t i = 0; i < n; i++)
    {
        sum = 0;
        for (size_t j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum > max) max = sum;
        }
        
    }
    printf("%d\n", max);
    
    

















    return 0;
} 