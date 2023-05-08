#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

noAVL * newTree(char inicial){
    noAVL * new = (noAVL *) malloc(sizeof(noAVL));
    new->fb = 0;
    new->letra = inicial;
    new->pai = NULL;
    new->dir = NULL;
    new->esq = NULL;
    return new;
}

void procuraNo(noAVL *atual, char palavra[20]){ //encontra o nó que vai ser inserido
    char inicial = palavra[0];

    while(atual->letra != inicial){
        if(atual->letra > inicial){
            if(atual->esq != NULL)
                atual = atual->esq;
        }else if(atual->letra < inicial){
            if(atual->dir != NULL)
                atual = atual->dir;
        }
    }
}

void inserir(noAVL ** raiz){

    char palavra[20];

    while(palavra[0] != "0"){
        scanf("%s", palavra);
        char inicial = palavra[0];

        if(*raiz == NULL){
            *raiz = newTree(inicial);
            (*raiz)->inicio = newList(palavra);
        }

        noAVL * atual;
        atual = *raiz;
        if(inicial == "0")
            break;
        else{
            procuraNo(&atual, palavra);
            newWord(&atual->inicio, palavra);
        }
    }

    return;
}