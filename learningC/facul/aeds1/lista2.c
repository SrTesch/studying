#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 254



typedef struct no{
    char file_name[30];
    char c[MAX_LINE_LENGTH];
    struct no *prox;
}no;

typedef struct lista{
    no *cab;
    no *ret;
    int tamanho;
}lista;


void leitura(no *cab, char valor[]){

}

void insere(no *ret, char valor[]){
    no *p = (no *) malloc(sizeof(no));
    strcpy(p->c, valor);
    p->prox = ret;
    ret->prox = p;
}

void imprime(no *cab){
    no *p = cab->prox;
    while(p != NULL){
        printf("%d\n", p->c);
        p = p->prox;
    }
}

int main(){
    int whatToDo = 1;
    no *cab = (no *) malloc(sizeof(no));
    cab->prox = NULL;

    while(whatToDo != 0){
        printf("Digite 1 para Inserir um item novo na lista, 2 para printar e 0 para sair: ");
        scanf("%d", &whatToDo);

        if(whatToDo == 1){
            
            char valor[30];
            printf("Digite o nome do arquivo que deseja inserir: ");
            scanf("%s", valor);
            
            insere(cab, valor);

        }else if(whatToDo == 2)
            imprime(cab);
    }
}
