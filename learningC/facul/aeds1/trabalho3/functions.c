#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <unistd.h>

void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}

void enterVoltar() {
    char aux;
    printf("\nPressione ENTER para voltar.");
    scanf("%c", &aux);
    getchar();
}

no *criarLista(){
    no *cab = (no*)malloc(sizeof(no));
    cab->prox = NULL;

    for(int i = 0; i < MAX_LIST_LENGHT; i++){
        no *atual = (no*)malloc(sizeof(no)); // cria um novo nó
        atual->indice = MAX_LIST_LENGHT - i;
        atual->prox_arq = NULL;

        atual->prox = cab->prox;
        cab->prox = atual;
    }
    return cab;
}

no *inserir(no *inicio, char *text, char *nome_arq){
    no *atual = inicio->prox;

    while(strcmp(atual->nome_do_arquivo, "") != 0)
        atual = atual->prox;

    strcpy(atual->conteudo, text);
    strcpy(atual->nome_do_arquivo, nome_arq);
    inicio->prox_arq = atual;
    return atual;
}

int ler_arq(no *inicio, int espaços_livres){
    system("clear");

    no *ultimo = inicio;
    char nome_arq[50];
    printf("Digite o nome do arquivo que deseja inserir:\n");
    scanf("%s", nome_arq);
    int inseridos = 0;
    FILE *textfile;
    char texto[60];
    textfile = fopen(nome_arq, "r");
    if(textfile == NULL){
        printf("Arquivo vazio ou Não encontrado\n");
        enterVoltar();
        return 0;
    }
    int tam_arq = 0;

    while(fgets(texto, 60, textfile))
        tam_arq++;
    
    if(tam_arq > espaços_livres){
        printf("\x1B[1;31mInfelizmente não há mais espaços livres ou o arquivo é muito grande!\nTente apagar algum outro arquivo antes!\n");
        enterVoltar();
        return 0;
    }else{
        fseek(textfile, 0, SEEK_SET);
        while(fgets(texto, 60, textfile)){
            ultimo = inserir(ultimo, texto, nome_arq);
            inseridos++;
        }
    }
    fclose(textfile);
    puts("\x1b[1;33mArquivo Inserido!\x1b[1;36m");
    enterVoltar();
    return inseridos;
}

no *end_arq(no *inicio, char *nome_arq){
    no *atual = inicio->prox;

    while(strcmp(atual->nome_do_arquivo,nome_arq) != 0){//while que verifica se chegou no nome do arquivo.
        if(atual->prox == NULL ){
            puts("Arquivo ainda não foi inserido na lista!");
            break;
        }

        atual = atual->prox;
    }
    return atual;
}

int remover_arq(no *inicio){
    system("clear");
    int removidos = 0;

    char arq[50];
    printf("Digite o nome do arquivo que deseja remover: ");
    scanf("%s", arq);

    no *começo;
    no *anterior;
    começo = end_arq(inicio, arq);

    if(começo->prox == NULL){// isso aqui é pra caso o arquivo nao tenha sido inserido
        enterVoltar();
        return removidos;
    }
    while(começo){
        strcpy(começo->conteudo, "");
        strcpy(começo->nome_do_arquivo, "");
        anterior = começo;
        começo = começo->prox_arq;
        anterior->prox_arq = NULL;
        removidos++;
    }
    printf("\x1b[1;33mArquivo Removido!\x1b[1;36m");
    enterVoltar();
    return removidos;
}

void imprimir_arq(no *inicio){
    system("clear");
    
    char arq[50];
    printf("Digite o nome do arquivo que deseja buscar: ");
    scanf("%s", arq);

    no *começo;
    começo = end_arq(inicio, arq);
    
    if(começo->prox == NULL){ // isso aqui é pra caso o arquivo nao tenha sido inserido
        enterVoltar();
        return;
    }
    

    int contador = 0;
    while(começo){
        printf("\x1B[1;33mBloco nº%d\n", começo->indice);
        printf("  Conteúdo=> %s\n", começo->conteudo);
        printf("  Endereço de memória=> %p\n", começo);
        começo = começo->prox_arq;
        contador++;
    }

    printf("\nOcupa %d Blocos\n\x1b[1;36m", contador);
    enterVoltar();
    return;
}

void imprimir_lista(no *inicio){
    no *atual = inicio;
    while(atual != NULL){
        printf("Nó - %d\n", atual->indice);
        printf("  Nome do arquivo - %s\n", atual->nome_do_arquivo);
        printf("  Endereço - %p\n", atual);
        printf("  Conteudo - %s\n", atual->conteudo);
        atual = atual->prox;
    }
    printf("\n");
    enterVoltar();
}