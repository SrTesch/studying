#ifndef __arvore_h
#define __arvore_h

#include <stdlib.h>
#include <stdio.h>

#include "../lista/lista.h"

typedef struct noAVL{
    char letra; //indice que vai servir para indexação (?) da arvore
    int fb; //fator de balanceamento
    list * inicio;
    noAVL * pai;
    noAVL * esq;
    noAVL * dir;
}noAVL;

noAVL * newTree(char inicial);

noAVL * procuraNo(noAVL *atual, char palavra[20]);

int inserir(noAVL ** raiz);

#endif