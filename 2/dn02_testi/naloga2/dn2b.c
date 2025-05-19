#include <stdio.h>

int A(char inp){
    inp = getchar();
    while(inp != ' ' || inp != '\n') {
        if(inp < '0' || inp > '9') return 0;
        printf("%c\n", inp);
        inp = getchar();
    }
    return 1;
}
int B(char inp){
    while(inp != ' ' || inp != '\n') {
    }
    
}
int C(char inp){
    
    while(inp != ' ' || inp != '\n') {
    }
}
int D(char inp){
    while(inp != ' ' || inp != '\n') {
    }

}


int main() {
    char inp;
    inp = getchar();





    if(inp == '0') {





    }
    else {
        // putchar(A(inp) + '0');
        printf("%d\n", A(inp));
    } 
















    return 0;
}

// 1 -> A
// 0 -> 0 -> B 
//      x -> C
//      b -> D