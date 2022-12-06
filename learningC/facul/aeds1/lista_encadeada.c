#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int c;
    struct lista *prox;
}lista;


int main(){
    lista *cab = (lista *)malloc(sizeof(lista));
    cab->prox = NULL;
    lista *p = (lista *) malloc(sizeof(lista));
    p->c = 15;
    p->prox = cab->prox;
    cab->prox = p;
    lista *q;

    for(int i = 0; i < 30; i += 5){
        q = p;
        p = p->prox;
        p = (lista *) malloc(sizeof(lista));
        scanf("%d", &p->c);
        p->prox = q->prox;
        q->prox = p;
    }


    p = cab->prox;
    while(p != NULL){
        printf("%d\n", p->c*2);
        p = p->prox;
    }
}