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

no ** criarLista(){
    no **fs = malloc(sizeof(no *) * MAX_LIST_LENGHT);

    for(int i = 0; i < MAX_LIST_LENGHT; i++){
        fs[i] = malloc(sizeof(no)); // cria um novo nó
        fs[i]->prox_arq = -1;
    }
    return fs;
}

int inserir(int inicio, char *text, no ** lista){
    int aux = inicio + 1;
    
    while(strcmp(lista[aux]->conteudo, "") != 0){
        aux++;
    }

    strcpy(lista[aux]->conteudo, text);
    lista[inicio]->prox_arq = aux; 
    return aux;
}

int ler_arq(no **lista, int espaços_livres, arquivo ** lista_arq){
    system("clear");
    int inicial = 0, ultimo = 0, inseridos = 0;

    char arq[60];
    printf("Digite o nome do arquivo que deseja inserir:\n");
    scanf("%s", arq);

    
    FILE *textfile;
    char texto[60];
    textfile = fopen(arq, "r");
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
        fgets(texto, 60, textfile);
        inicial = inserir(ultimo, texto, lista);
        ultimo = inicial;
        while(fgets(texto, 60, textfile)){
            ultimo = inserir(ultimo, texto, lista);
            inseridos++;
        }
    }
    fclose(textfile);

    /* Nesta parte o arquivo está sendo inserido na lista de arquivos com todos os seus metadados! */
    for(int i = 0; i < 100; i++){
        if(lista_arq[i] == NULL){    
            lista_arq[i] = malloc(sizeof(arquivo)); //criando um novo nó
            strcpy(lista_arq[i]->nome_do_arquivo, arq);
            lista_arq[i]->inicio = inicial;
            lista_arq[i]->num_blocos = tam_arq;
            break;
        }
    }

    puts("\x1b[1;33mArquivo Inserido!\x1b[1;36m");
    enterVoltar();
    return inseridos;
}

int end_arq(arquivo ** lista_arq, char arq){
    int começo;
    for(int i = 0; i < 100; i++){
        if(strcmp(lista_arq[i]->nome_do_arquivo, &arq) == 0){
            começo = lista_arq[i]->inicio;
            return começo;
        }
    }
    printf("Poxa, parece que este arquivo ainda não foi inserido."); // caso o arquivo nao tenha sido inserido ainda
    return -1;
}

int remover_arq(arquivo ** lista_arq, no **lista){
    system("clear");
    int removidos = 0;
    int começo, anterior, tamanho_arq;
    char arq[50];
    printf("Digite o nome do arquivo que deseja remover: ");
    scanf("%s", arq);
    
    começo = end_arq(lista_arq, &arq);
    if(começo == -1){
        printf("Parece que este arquivo ainda não foi inserido\n");
        return removidos;
    }

    int aux;
    for(int i = 0; i < 100; i++){
        if(strcmp(lista_arq[i]->nome_do_arquivo, arq) == 0){
            aux = i;
            break;
        }
    }
    
    for(int j = 0; j < tamanho_arq; j++){
        strcpy(lista[começo]->conteudo, "");
        anterior = começo;
        começo = lista[começo]->prox_arq;
        lista[anterior]->prox_arq = -1;
        removidos++;
    }

    lista_arq[aux] == NULL;
    printf("\x1b[1;33mArquivo Removido!\x1b[1;36m");
    enterVoltar();
    return removidos;
}

void imprimir_arq(arquivo ** lista_arq, no **lista){
    system("clear");
    char arq[50];
    printf("Digite o nome do arquivo que deseja buscar: ");
    scanf("%s", arq);

    int começo = end_arq(lista_arq, &arq);
    int tamanho_arq = lista_arq[começo]->num_blocos;
    for(int i = 0; i < tamanho_arq; i++){
        printf("\x1B[1;33mBloco nº%d\n", i);
        printf("  Conteúdo=> %s\n", lista[começo]->conteudo);
        printf("  Endereço de memória=> %p\n", lista[começo]);
        começo = lista[começo]->prox_arq;
    }

    printf("\nOcupa %d Blocos\n\x1b[1;36m", tamanho_arq);
    enterVoltar();
    return;
}

void imprimir_lista(arquivo ** lista_arq, no ** lista){
    for(int i = 0; i < MAX_LIST_LENGHT; i++){
        printf("Nó - %d\n", i+1);
        printf("  Endereço - %p\n", lista[i]);
        printf("  Conteudo - %s\n", lista[i]->conteudo);
    }
    
    puts("Arquivos inseridos:");
    puts("Nome do Arquivo - Inicio - Tamanho");

    int aux = 0;
    while(strcmp(lista_arq[aux]->nome_do_arquivo, "") == 0 ){
        printf("%s - %d - %d\n", lista_arq[aux]->nome_do_arquivo, lista_arq[aux]->inicio, lista_arq[aux]->num_blocos);
        aux++;
    }
    printf("\n");
    enterVoltar();
}
