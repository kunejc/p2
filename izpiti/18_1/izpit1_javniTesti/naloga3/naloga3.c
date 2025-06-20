
/*
 * Va"sa re"sitev tretje naloge --- datoteko dopolnite in jo oddajte na spletno u"cilnico!
 *
 * Your solution to task 3 --- complete the file and submit it to U"cilnica!
 *
 * V naslednjo vrstico vpi"site va"so vpisno "stevilko / Enter your student ID number in the next line:
 *
 */

#include <stdio.h>
#include <stdlib.h>

// Primerjalna funkcija za qsort (padajoče urejanje)
int compare_desc(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return y - x;
}

int main() {
    int n;
    scanf("%d", &n);

    int stevila[20];  // Ker je n največ 20
    for (int i = 0; i < n; i++) {
        scanf("%d", &stevila[i]);
    }

    // Uredi od največjega proti najmanjšemu
    qsort(stevila, n, sizeof(int), compare_desc);

    long long vsota1 = 0, vsota2 = 0;

    for (int i = 0; i < n; i++) {
        if (vsota1 < vsota2) {
            vsota1 += stevila[i];
        } else {
            vsota2 += stevila[i];
        }
    }

    long long razlika = llabs(vsota1 - vsota2);
    printf("%lld\n", razlika);

    return 0;
}

