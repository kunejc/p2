#include <stdio.h>
#include <math.h>

#define MAX 100000000000000000

long long obrni(long long st) {
    long long obrnjeno = 0;
    while(st > 0){
        obrnjeno = obrnjeno*10 + st%10;
        st /= 10;
        // printf("%d", 0);
    }

    return obrnjeno;
}

long long sestej(long long a, long long b) {
    return a + b;
}

int jePalindrom(long long stevilo) {
    return stevilo == obrni(stevilo);
}

int testiraj(long long stevilo, int k) {
    // int prvoNadMax = 1;
    long long pravilno = stevilo;
    for (int i = 0; i < k; i++)
    {
        long long obrnjeno = obrni(pravilno);
        long long sesteto = sestej(pravilno, obrnjeno);
        // printf("%lld / %lld\n", obrnjeno, sesteto);
        if(sesteto > 10e17){
            sesteto += obrni(sesteto);
            if(jePalindrom(sesteto)) return 0;
            return 1;
            
            // printf("%lld / %lld\n", stevilo, sesteto);
        }
        if(jePalindrom(sesteto)){
            return 0;
        } 
        else { 
            pravilno = sesteto;
            // printf("%lld / %lld\n", stevilo, sesteto);
        }
        
        
    }
    



    return 1;
}




int main() {
    long long k, a, b;
    int sum = 0;
    scanf("%lld %lld %lld", &k, &a, &b);
    for (int i = a; i < b+1; i++){
        sum += testiraj(i, k);
    }
    
    printf("%d\n", sum);
    return 0;
}

// obrnemo
// in pristejemo obrnjeni stevili
// pogledamo ce je palindrom
// ponavljamo n-krat