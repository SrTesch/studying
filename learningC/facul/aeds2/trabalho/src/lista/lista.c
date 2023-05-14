#include "lista.h"

list * newList(char p[20]){
    list * new = (list *) malloc(sizeof(list));
    strcpy(new->palavra, p);
    new->prox = NULL;
    new->ant = NULL;
    return new;
}

int searchInList(list ** lista, char p[20]){
    list * atual = (*lista);

    if(strcmp(atual, p))
        return 1;
    
    while(atual != NULL){
        atual = atual->prox;
        if(strcmp(atual, p))
            return 1;
    }

    return 0;
}

int newWord(list ** lista, char p[20]){
    
    if(searchInList(&lista, p) == 1){
        printf("Esta palavra já foi inserida\n");
        return 0;
    }

    list * aux;
    aux = (*lista)->prox;

    list * new = (list *) malloc(sizeof(list));
    strcpy(new->palavra, p);

    (*lista)->prox = new; 
    new->ant = (*lista);
    
    new->prox = aux;
    aux->ant = new;
    return 1;
}