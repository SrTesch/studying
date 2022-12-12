#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


void leitura(lista *lista, char *arq){
    FILE *textfile;
    char texto[MAX_LINE_LENGTH];
     
    textfile = fopen(arq, "r");
    if(textfile == NULL)
        printf("Arquivo vazio ou Não encontrado\n");
     
    while(fgets(texto, MAX_LINE_LENGTH, textfile)){
        inserirFim(lista, texto, arq);
    }
    fclose(textfile);
}

// inserir no final da lista
void inserirFim(lista *lista, char *valor, char *name){
    no *p = (no*)malloc(sizeof(no)); // cria um novo nó
    strcpy(p->c, valor);
    strcpy(p->file_name, name);
    p->prox = NULL;

    if(lista->cab == NULL) { // lista vazia
        lista->cab = p;
        lista->ret = p;
    } else { // lista não vazia
        lista->ret->prox = p;
        lista->ret = p;
    }
    lista->tam++;
}

// imprimir a lista
void imprime(lista *lista) {
    no *cab = lista->cab;
    printf("Tamanho da lista: %d\n", lista->tam);
    while(cab != NULL) {
        printf("%s\n", cab->c);
        printf("%s\n", cab->file_name);
        cab = cab->prox;
    }
    printf("\n\n");
}

int main(){
    char file_name[30];

    lista lista;
    lista.cab = NULL;
    lista.ret = NULL;
    lista.tam = 0;
    printf("Digite o nome do arquivo que voce deseja inserir: ");
    scanf("%s", file_name);
    leitura(&lista, file_name);
    imprime(&lista);
}