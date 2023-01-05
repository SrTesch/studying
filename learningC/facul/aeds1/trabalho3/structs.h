#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIST_LENGHT 500

typedef struct __no_geral{
    char conteudo[60]; //conteudo do arquivo
    int prox_arq;
}no;

typedef struct __arquivo{
    char nome_do_arquivo[30]; 
    int inicio; //marcando o inicio do arquivo
    int num_blocos; //tamanho do arquivo na lista
}arquivo;