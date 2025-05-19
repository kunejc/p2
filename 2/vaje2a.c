#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, counter = 0;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= b; k++) {
                if(j*j + k*k == i*i) {
                    counter++;
                    // printf("%d + %d = %d\n", j, k, i);
                    i++;
                }
            }
            
        }
        
    }
    
    printf("%d\n", counter);

    return 0;
}