#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int c;
    struct no *prox;
}no;


int main(){
    no *cab = (no *)malloc(sizeof(no));
    cab->prox = NULL;
    no *p = (no *) malloc(sizeof(no));
    p->c = 15;
    p->prox = cab->prox;
    cab->prox = p;
    no *q;

    for(int i = 0; i < 30; i += 5){
        q = p;
        p = p->prox;
        p = (no *) malloc(sizeof(no));
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