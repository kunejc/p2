#include <stdio.h>


int main() {
    // char jeVeljavno = '1';

    char inp = getchar();

    int stanje = 1;
    while(inp != '\n') {
        if(inp == '+' || inp == '-' || (inp >= '1' && inp <= '9' )) stanje = 1;






    }
    if()












    //     inp = getchar();
    //     while((inp >= '0' && inp <= '9' ))



    // }
    // else if (getchar() == '0');
    // else jeVeljavno = '0';
    






    if(stanje) putchar('1');
    else putchar('0');
    // putchar(jeVeljavno);
    return 0;
}