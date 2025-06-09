
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
            if (!strcmp(student->po[i].predmet, predmet)) return i;
                      
        }   
    return -1;
}

int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    int indexIskanega = poisciStudenta(studentje, stStudentov, vpisna);
    if (indexIskanega == -1)
    {
        stStudentov++;
        struct _Student* novStudent = malloc(sizeof(struct _Student));
        novStudent->vpisna = vpisna;
        novStudent->po = malloc(10*sizeof(struct _PO));
        novStudent->po[0].ocena = ocena;
        strcpy(novStudent->po[0].predmet, predmet);
        novStudent->stPO = 1;

        studentje[stStudentov-1] = novStudent;
    }
    else {
        int indexPredmeta = poisciPO(studentje[indexIskanega], predmet);
        if (indexPredmeta == -1)
        {
            int i = studentje[indexIskanega]->stPO;
            struct _PO* novPredmet = malloc(sizeof(struct _PO));
            strcpy(novPredmet->predmet, predmet);
            novPredmet->ocena = ocena;
            studentje[indexIskanega]->po[i] = *novPredmet;
            studentje[indexIskanega]->stPO++;
        }
        else studentje[indexIskanega]->po[indexPredmeta].ocena = ocena;
    
    }




    return stStudentov;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
