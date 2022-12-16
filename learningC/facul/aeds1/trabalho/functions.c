#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <unistd.h>

// inserir no final da lista
void inserirFim(lista *lista, char *valor, char *nome){
    if(lista->tam >= MAX_LENGHT){
        puts("Lista Cheia!!! Remova algum arquivo para poder inserir um novo");
        return;
    }

    no *atual = (no*)malloc(sizeof(no)); // cria um novo nó
    strcpy(atual->conteudo, valor);
    strcpy(atual->nome_do_arquivo, nome);
    atual->prox = NULL;

    if(lista->cab == NULL) { // lista vazia
        lista->cab = atual;
        lista->ret = atual;
    } else { // lista não vazia
        lista->ret->prox = atual;
        lista->ret = atual;
    }
    lista->tam++;
}


void leitura(lista *lista){
    system("clear");

    char arq[50];
    printf("Digite o nome do arquivo que deseja inserir:\n");
    scanf("%s", arq);

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
    printf("Tamanho atual da lista: %d\n", lista->tam);
    
}


conteudo_buscado *busca(lista *lista, char *arq){
    no *atual = lista->cab;
    no *inicial = NULL;
    no *anterior = NULL;
    conteudo_buscado * conteudo = (conteudo_buscado *)malloc(sizeof(conteudo_buscado));

    if(atual == NULL){ // lista vazia
        puts("Lista Vazia! Insira algum arquivo para poder busca-lo");
        return conteudo;
    }

    while(strcmp(atual->nome_do_arquivo,arq) != 0){//while que verifica se chegou no nome do arquivo.
        if(atual->prox == NULL ){
            return 0;
        }
        anterior = atual;
        atual = atual->prox;
    }


    inicial = atual;

    conteudo->inicial = inicial;
    conteudo->anterior = anterior;
    return conteudo;
}


void imprimir_arq(lista *lista){
    system("clear");
    
    char arq[50];
    printf("Digite o nome do arquivo que deseja buscar: ");
    scanf("%s", arq);

    conteudo_buscado *arquivo = busca(lista, arq);
    if(arquivo != NULL){
        no *atual = arquivo->inicial;
        int count = 1;
        while(strcmp(atual->nome_do_arquivo,arq) == 0){//esse while percorre o arquivo desejado.
            if(atual->prox == NULL){
                printf("%d - %p\n", count, atual);
                break;
            }else{
                printf("%d - %p\n", count, atual);
                count++;
                atual = atual->prox;
            }
        }
        puts("");
    }else
        puts("Arquivo não encontrado!");
}

void remove_arq(lista *lista){
    system("clear");

    char arq[50];
    scanf("%s", arq);
    printf("Digite o nome do arquivo que deseja remover: ");

    conteudo_buscado *arquivo = busca(lista, arq);
    no *atual = arquivo->inicial;
    no *aux;
    if(arquivo->anterior){ //verificando se não é o primeiro da lista
        aux = arquivo->anterior;
        while(strcmp(atual->nome_do_arquivo,arq) == 0 && aux->prox != NULL){//esse while percorre o arquivo desejado.
            aux->prox = atual->prox;
            free(atual);
            lista->tam--;
            if(aux->prox == NULL){
                lista->ret = aux;
                break;
            }
            atual = aux->prox;
        }
    }else{
        while(strcmp(atual->nome_do_arquivo,arq) == 0 && aux->prox != NULL){
            aux->prox = atual->prox;
            free(atual);
            atual = aux->prox;
            lista->tam--;
            if(atual == NULL){
                lista->cab = NULL;
                lista->ret = NULL;
                break;
            }
            lista->cab = atual;
        }
    }
}

void imprime(lista *lista){
    system("clear");
    no *cab = lista->cab;
    int count = 1;
    while(cab != NULL){
        printf("Nó - %d\n", count);
        printf("  Nome do arquivo - %s\n", cab->nome_do_arquivo);
        printf("  Endereço - %p\n", cab);
        printf("  Conteudo - %s\n", cab->conteudo);
        cab = cab->prox;
        count++;
    }
    printf("Tamanho da lista: %d\n", lista->tam);
    printf("\n");
}