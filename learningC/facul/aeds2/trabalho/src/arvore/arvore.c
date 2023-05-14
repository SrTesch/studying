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
    new->inicio = NULL;
    return new;
}

noAVL * newNode(noAVL ** pai, char inicial){
    noAVL * new = (noAVL *) malloc(sizeof(noAVL));
    new->fb = 0;
    new->letra = inicial;
    new->pai = (*pai);
    new->inicio = NULL;
    return new;
}

void rotaciona(){
    return;
}

noAVL * procuraNo(noAVL *atual, char palavra[20]){
    char inicial = palavra[0];

    while(atual->letra != inicial){
        if(atual->letra > inicial){
            if(atual->esq != NULL)
                atual = atual->esq;
            else{
                noAVL * new = newNode(&atual, inicial);
                atual->fb += 1;
                if(atual->fb > 1 || atual->fb < -1)
                    rotaciona();
                atual->esq = new;
                return new;
            }
        }else if(atual->letra < inicial){
            if(atual->dir != NULL)
                atual = atual->dir;
            else{
                noAVL * new = newNode(&atual, inicial);
                atual->fb -= 1;
                if(atual->fb > 1 || atual->fb < -1)
                    rotaciona();
                atual->dir = new;
                return new;
            }
        }
    }
    return atual;
}

int inserir(noAVL ** raiz){
    //TODO: alterar o Fator de balanceamento quando insere uma palavra.
    char palavra[20];
    int cont = 0;
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
            printf("Node before 'procuraNo' -> %c\n", atual->letra);
            atual = procuraNo(&atual, palavra);
            printf("Node after 'procuraNo' -> %c\n", atual->letra);
            int verificador;
            verificador = newWord(&atual->inicio, palavra);
            if(verificador == 1)
                cont++;
        }
    }
    printf("Todos os dados foram carregados com sucesso!!\n");

    return cont;
}