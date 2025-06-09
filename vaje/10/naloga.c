
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int poisciStudenta(Student** studentje, int stStudentov, int vpisna) {
    for (size_t i = 0; i < stStudentov; i++)
    {
        if (studentje[i]->vpisna == vpisna) return i;
    }
    return -1;
}

int poisciPO(Student* student, char* predmet) {
    for (size_t i = 0; i < student->stPO; i++)
    {
        if (strcmp(student->po[i].predmet, predmet) == 0) return i;
    }
    return -1;
}

int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    if (poisciStudenta(studentje, stStudentov, vpisna) == -1)
    {
        struct _Student *novStudent = malloc(sizeof(struct _Student));
        novStudent->vpisna = vpisna;
        novStudent->stPO = 1;
        novStudent->po = malloc(10*sizeof(struct _PO));
        novStudent->po[0].ocena = ocena;
        strcpy(novStudent->po[0].predmet, predmet);
        studentje[stStudentov] = novStudent;
        stStudentov++;
    }
    else {
        struct _Student *trenutni = studentje[poisciStudenta(studentje, stStudentov, vpisna)];
        int indexPO = poisciPO(studentje[poisciStudenta(studentje, stStudentov, vpisna)], predmet);

        if (indexPO == -1)
        {
            struct _PO novPO;
            novPO.ocena = ocena;
            strcpy(novPO.predmet, predmet);
            trenutni->po[trenutni->stPO] = novPO;
            trenutni->stPO++;
        } else {
            trenutni->po[indexPO].ocena = ocena;
        }
        
       
    }

    


    return stStudentov;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
