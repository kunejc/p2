#include <stdio.h>
#include <stdbool.h>

void printNumber(int num) {
    if (num == 0) {
        putchar('0');
        return;
    }
    if (num < 0) {
        putchar('-');
        num *= -1;
    }
    if (num / 10) {
        printNumber(num / 10);
    }
    putchar((num % 10) + 48);
}

int getNumBin() {
    int x = getchar();
    int num = 0;
    while (x!='1' && x!='\n'){
        x = getchar();
    }
    while (x!='\n'){
        num = num*2 + (x-'0');
        x = getchar();
    }
    return num;
}

int getLog(int num){
    int cur = num;
    int preliv = 0;
    int log = 0;

    if (cur & 1){
        preliv++;
    }
    
    while(cur > 1){
        if (cur & 1){
            preliv++;
        }
        log++;
        cur >>= 1;
        // printf("%d\n", preliv);

    }

    if(preliv == 0) return log;
    else return log+1;
}



int main (){
    int num = getNumBin();
    int log = getLog(num);

    printNumber(log);
    putchar('\n');
      
    return 0;
}