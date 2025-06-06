#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int recursive(int* t, int n, int i, int sum, int maxSum) {

    if(i == n) return maxSum > sum ? maxSum : sum;

    int take = recursive(t, n, i+1, sum + t[i], maxSum);

    int skip = recursive(t, n, i+1, 0, sum > maxSum ? sum : maxSum);

    return take > skip ? take : skip;
}

int recursiveSetter(int* t, int n) {
    return recursive(t, n, 0, 0, INT_MIN);
}
    
int main() {

    int n = 0;
    scanf("%d", &n);

    int max_sum = INT_MIN; int temp_sum = 0;
    int* t = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
        temp_sum += t[i];

        if(temp_sum > max_sum) max_sum = temp_sum;
        if(temp_sum < 0) temp_sum = 0;        
    }

    printf("%d\n", max_sum);

    return 0;
}