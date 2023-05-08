#include "lista.h"

list * newList(char p[20]){
    list * new = (list *) malloc(sizeof(list));
    strcpy(new->palavra, p);
    new->prox = NULL;
    new->ant = NULL;
    return new;
}

void newWord(list ** lista, char p[20]){
    list * aux;
    aux = (*lista)->prox;

    list * new = (list *) malloc(sizeof(list));
    strcpy(new->palavra, p);

    (*lista)->prox = new; 
    new->ant = (*lista);
    
    new->prox = aux;
    aux->ant = new;
}