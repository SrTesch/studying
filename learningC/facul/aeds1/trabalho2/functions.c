#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <unistd.h>

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

noGeral* criarLista(){
    noGeral *cab = (noGeral*)malloc(sizeof(noGeral));
    cab->prox = NULL;

    for(int i = 0; i < 100; i++){
        noGeral *atual = (noGeral*)malloc(sizeof(noGeral)); // cria um novo nó
        atual->indice = 100 - i;
        atual->prox_arq = NULL;

        atual->prox = cab->prox;
        cab->prox = atual;
    }

    return cab;
}

noGeral *inserir(noGeral *inicio, char *text, char *nome_arq){
    noGeral *atual = inicio->prox;

//    if(atual == NULL){
//        printf("Não foi possível inserir este arquivo");
//        return;
//    }
    int x= 1;
    while(x){
        if(atual->nome_do_arquivo != NULL)
            atual = atual->prox;
        else
            break;
    }
    strcpy(atual->conteudo, text);
    strcpy(atual->nome_do_arquivo, nome_arq);
    inicio->prox = atual;
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