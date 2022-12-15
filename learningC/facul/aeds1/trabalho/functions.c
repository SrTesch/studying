#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <unistd.h>

// inserir no final da lista
void inserirFim(lista *lista, char *valor, char *name){
    if(lista->tam >= MAX_LENGHT){
        puts("Lista Cheia!!! Remova algum arquivo para poder inserir um novo");
        return;
    }

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

    puts("Arquivo Inserido!");
}


conteudo_buscado *busca(lista *lista, char *arq){
    no *atual = lista->cab;
    no *inicial;
    if(atual == NULL){ // lista vazia
        puts("Lista Vazia! Insira algum arquivo para poder busca-lo");
        return 0;
    }

    while(strcmp(atual->file_name,arq) != 0){//while que verifica se chegou no nome do arquivo.
        if(atual->prox == NULL ){
            puts("Arquivo Não Inserido!");
            return 0;
        }
        atual = atual->prox;
    }

    int count = 1;

    inicial = atual;

    while(strcmp(atual->file_name,arq) == 0 && atual != NULL){//esse while percorre o arquivo desejado.
        if(atual->prox == NULL)
            break;
        else
            atual = atual->prox;

        count++;
    }

    conteudo_buscado * conteudo = (conteudo_buscado *)malloc(sizeof(conteudo_buscado));
    conteudo->inicial = inicial;
    conteudo->tam = count;

    return conteudo;
}


void buscar_arq(lista *lista, char *arq){
    system("clear");
    conteudo_buscado *arquivo = busca(lista, arq);

    no *atual = arquivo->inicial;
    int tamanho = arquivo->tam;

    for(int i = 1; i <= tamanho; i++){
        printf("%d - %p\n", i, atual);
        atual = atual->prox;
    }
}

void remove_arq(lista *lista, char *arq){
    system("clear");
    conteudo_buscado *arquivo = busca(lista, arq);
    no *atual = arquivo->inicial;
    no *aux = atual;
    
    int tamanho = arquivo->tam;

    for(int i = 1; i <= tamanho; i++){
        aux->prox = atual->prox;
        free(atual);
        atual = aux->prox;
        lista->tam--;
    }
}

void imprime(lista *lista) {
    no *cab = lista->cab;
    printf("Tamanho da lista: %d\n", lista->tam);
    while(cab != NULL) {
        printf("%s\n", cab->c);
        printf("%s\n", cab->file_name);
        cab = cab->prox;
    }
    printf("\n");
}