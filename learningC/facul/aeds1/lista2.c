#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int c;
    struct lista *prox;
}lista;

void insere(lista *cab, int valor){
    lista *p = (lista *) malloc(sizeof(lista));
    p->c = valor;
    p->prox = cab->prox;
    cab->prox = p;
}

void imprime(lista *cab){
     lista *p = cab->prox;
    while(p != NULL){
        printf("%d\n", p->c);
        p = p->prox;
    }
}

int main(){
    int whatToDo = 1;
    lista *cab = (lista *) malloc(sizeof(lista));
    cab->prox = NULL;

    while(whatToDo != 0){
        printf("Digite 1 para Inserir um item novo na lista, 2 para printar e 0 para sair: ");
        scanf("%d", &whatToDo);

        if(whatToDo == 1){
            
            int valor;
            printf("Digite o valor que deseja inserir: ");
            scanf("%d", &valor);
            insere(cab, valor);

        }else if(whatToDo == 2) imprime(cab);
    }
}
