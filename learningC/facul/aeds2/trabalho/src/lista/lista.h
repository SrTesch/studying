#ifndef __lista_h
#define __lista_h

#include <stdlib.h>
#include <stdio.h>
#include "lista.c"
#include "../arvore/arvore.h"

typedef struct list{
    char palavra[20];
    list * prox;
    list * ant;
}list;

list * newList(char p[20]);

int searchInList(list ** lista, char p[20]);

int newWord(list ** lista, char p[20]);

#endif