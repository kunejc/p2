#include <stdio.h>

int main() {
    int low, high;
    int input;
    int scam = 0;

    scanf("%d %d", &low, &high);
    scanf("%d", &input);
    
    while(input != 0) {
        
        
        int mid = (low+high)/2;
        
        if(high == low) scam =1;
        
        
        
        if (input == 1) low = mid+1;
        if (input == -1) high = mid-1;
        
        scanf("%d", &input);

    }
    if(scam) printf("PROTISLOVJE");
    else if(high==low) printf("%d", low);
    else printf("%d %d", low, high);
    





    return 0;
}