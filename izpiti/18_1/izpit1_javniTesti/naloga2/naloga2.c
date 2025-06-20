
/*
 * Va"sa re"sitev druge naloge --- datoteko dopolnite in jo oddajte na spletno u"cilnico!
 *
 * Your solution to task 2 --- complete the file and submit it to U"cilnica!
 *
 * V naslednjo vrstico vpi"site va"so vpisno "stevilko / Enter your student ID number in the next line:
 *
 */

#include "naloga2.h"
#include <stdint.h>

uchar* preberi(char* imeDatoteke, int* sirina, int* visina, int* stBajtov) {
    FILE *vhodna = fopen(imeDatoteke, "rb");
    if (!vhodna) return NULL;

    char buffer[10000];
    fgets(buffer, sizeof(buffer), vhodna); //P6
    
    fgets(buffer, sizeof(buffer), vhodna);  // visina sirina
    sscanf(buffer, "%d %d", sirina, visina);

    fgets(buffer, sizeof(buffer), vhodna); //255

    // *stBajtov = (*sirina) * (*visina) * 3;

    // uchar *bajti = malloc((*stBajtov) * sizeof(uchar));
    // fread(bajti, sizeof(uchar), *stBajtov, vhodna);    

    // return bajti;

    return NULL;
}




int sivina(uchar* pike, int sirina, int visina, int vrstica, int stolpec) {
    // popravite oz. dopolnite / modify and/or add ...
    return -1;
}

int main() {
    // po "zelji dodajte kodo za ro"cno testiranje ...
    // add manual testing code if desired ...
    return 0;
}
