#include <stdio.h>
#include <stdbool.h>

void printNumber(int sum) {
    if (sum == 0) {
        putchar('0');
        return;
    }

    if (sum < 0) {
        putchar('-');
        sum *= -1;
    }

    if (sum / 10) {
        printNumber(sum / 10);
    }
    putchar((sum % 10) + 48);
}

int main() {
    
    int a = 0;
    int apredznak = 1;
    int b = 0;
    int bpredznak = 1;
    int sum;
    
    char x;
    x = getchar();
    if (x == '-') {
        apredznak = -1;
        x = getchar();
    }
    
    while (x != ' ')
    {
        a = a * 10 + (x-48);
        x = getchar();
    }
    x = getchar();
    if (x == '-') {
        bpredznak = -1;
        x = getchar();
    }
    while (x != '\n')
    {
        b = b * 10 + (x-48);
        x = getchar();
    }
    
    sum = apredznak*a + bpredznak*b;
    
    printNumber(sum);
    putchar('\n');
    
    return 0;
}