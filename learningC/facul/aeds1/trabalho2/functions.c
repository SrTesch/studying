#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <unistd.h>

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

noGeral *criarLista(){
    noGeral *cab = (noGeral*)malloc(sizeof(noGeral));
    cab->prox = NULL;

    for(int i = 0; i < 500; i++){
        noGeral *atual = (noGeral*)malloc(sizeof(noGeral)); // cria um novo nó
        atual->indice = 500 - i;
        atual->prox_arq = NULL;

        atual->prox = cab->prox;
        cab->prox = atual;
    }

    return cab;
}

noGeral *inserir(noGeral *inicio, char *text, char *nome_arq){
    noGeral *atual = inicio->prox;

    while(strcmp(atual->nome_do_arquivo, "") != 0)
        atual = atual->prox;

    strcpy(atual->conteudo, text);
    strcpy(atual->nome_do_arquivo, nome_arq);
    inicio->prox_arq = atual;
    return atual;
}

void inserir_arq(noGeral *inicio){
    system("clear");

    noGeral *ultimo = inicio;
    char nome_arq[50];
    printf("Digite o nome do arquivo que deseja inserir:\n");
    scanf("%s", nome_arq);

    FILE *textfile;
    char texto[50];
    textfile = fopen(nome_arq, "r");
    if(textfile == NULL){
        printf("Arquivo vazio ou Não encontrado\n");
        return;
    }
    while(fgets(texto, 50, textfile)){
        ultimo = inserir(ultimo, texto, nome_arq);
        //if(ultimo == -1){}
    }
    fclose(textfile);

    puts("Arquivo Inserido!");
}

noGeral *end_arq(noGeral *inicio, char *nome_arq){
    noGeral *atual = inicio->prox;

    while(strcmp(atual->nome_do_arquivo,nome_arq) != 0){//while que verifica se chegou no nome do arquivo.
        if(atual->prox == NULL ){
            puts("Arquivo ainda não foi inserido na lista!");
            break;
        }

        atual = atual->prox;
    }
    return atual;
}

void remover_arq(noGeral *inicio){
    system("clear");

    char arq[50];
    printf("Digite o nome do arquivo que deseja remover: ");
    scanf("%s", arq);

    noGeral *começo;
    noGeral *anterior;
    começo = end_arq(inicio, arq);

    if(começo->prox == NULL){// isso aqui é pra caso o arquivo nao tenha sido inserido
        return;
    }

    while(começo){
        strcpy(começo->conteudo, "");
        strcpy(começo->nome_do_arquivo, "");
        anterior = começo;
        começo = começo->prox_arq;
        anterior->prox_arq = NULL;
    }
}

void imprimir_arq(noGeral *inicio){
    system("clear");
    
    char arq[50];
    printf("Digite o nome do arquivo que deseja buscar: ");
    scanf("%s", arq);

    noGeral *começo;
    começo = end_arq(inicio, arq);
    
    if(começo->prox == NULL){ // isso aqui é pra caso o arquivo nao tenha sido inserido
        return;
    }
    

    int contador = 0;
    while(começo){
        printf("Bloco nº%d\n", começo->indice);
        printf("  Conteúdo=> %s\n", começo->conteudo);
        printf("  Endereço de memória=> %p\n", começo);
        começo = começo->prox_arq;
        contador++;
    }

    printf("\nOcupa %d Blocos\n", contador);

    return;
}

void imprimir_lista(noGeral *inicio){
    noGeral *atual = inicio;
    while(atual != NULL){
        printf("Nó - %d\n", atual->indice);
        printf("  Nome do arquivo - %s\n", atual->nome_do_arquivo);
        printf("  Endereço - %p\n", atual);
        printf("  Conteudo - %s\n", atual->conteudo);
        atual = atual->prox;
    }
    printf("\n");
}