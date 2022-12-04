#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    char c;
    struct lista *prox;
}lista;


int main(){
    lista *p = (lista *)malloc(sizeof(lista));
    lista *q = (lista *)malloc(sizeof(lista));
    p->c = 'F';
    p->prox = q;
    q->c = 'A';
    q->prox = 0;
    printf("p->c: %c\n", p->c);
}