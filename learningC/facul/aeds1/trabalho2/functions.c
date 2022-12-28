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
        atual->indice = i;
        atual->prox_arq = NULL;

        atual->prox = cab->prox;
        cab->prox = atual;
    }

    return cab;
}

void inserir(noGeral *inicio, char *text, char *nome_arq){
    noGeral *atual = inicio;
    noGeral *ultimo;
    if(atual->conteudo){
        atual = atual->prox;
    }else{
        strcpy(atual->conteudo, text);
        strcpy(atual->nome_do_arquivo, nome_arq);
        ultimo = atual; // marcando o  ultimo inserido
    }

}


void inserir_arq(noGeral *inicio){
    system("clear");

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
        inserir(inicio, texto, nome_arq);
    }
    fclose(textfile);

    puts("Arquivo Inserido!");
}