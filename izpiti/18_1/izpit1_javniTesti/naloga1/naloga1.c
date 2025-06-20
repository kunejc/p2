
/*
 * Va"sa re"sitev prve naloge --- datoteko dopolnite in jo oddajte na spletno u"cilnico!
 *
 * Your solution to task 1 --- complete the file and submit it to U"cilnica!
 *
 * V naslednjo vrstico vpi"site va"so vpisno "stevilko / Enter your student ID number in the next line:
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n;
    char buffer[100000];

    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &n);

    
    int *osebe = calloc(n, sizeof(int));
    int i = 0;
    int count = n;
    
    fgets(buffer, sizeof(buffer), stdin);

    char *token = strtok(buffer, " \n");
    while (token != NULL && i < n)
    {
        osebe[i] = atoi(token);
        i++;
        token = strtok(NULL, " \n");
    }

    // for (int j = 0; j < n; j++) {
    //     printf("%d ", osebe[j]);
    // }
    // printf("\n");

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i; j < n; j++)
        {
            // printf("osebe[%zu] = %d, osebe[%zu] = %d\n", i, osebe[i], j, osebe[j]);
            if(osebe[i] < osebe[j]) {
                count--;
                break;
            }
        }
        
        
        
    }

    printf("%d\n", count);
    
    













    return 0;
}
