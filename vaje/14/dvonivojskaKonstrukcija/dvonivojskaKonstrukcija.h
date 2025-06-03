
#ifndef _DVONIVOJSKA_KONSTRUKCIJA_H
#define _DVONIVOJSKA_KONSTRUKCIJA_H

typedef struct Zunanje Zunanje;
typedef struct Notranje Notranje;

struct Zunanje {
    Notranje* prvo;
    Notranje* zadnje;
    Zunanje* dol;
};

struct Notranje {
    int podatek;
    Notranje* desno;
};

Zunanje* izdelajDvonivojsko(int* t, int n);

#endif
