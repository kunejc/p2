
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

void pozeni(char* niz, char znak) {
    char* kopija = kopirajDoZnaka(niz, znak);
    printf("<%s>\n", kopija);
    free(kopija);
}

int main() {
    char niz[] = "prijazen niz z enim samim presledkom med besedami";

    pozeni(niz, ' ');
    pozeni(niz, 'e');
    pozeni(niz, 'r');
    pozeni(niz, 'p');
    pozeni(niz, 't');

    exit(0);
    return 0;
}
