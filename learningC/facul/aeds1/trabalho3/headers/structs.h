#ifndef __structs.h
#define __structs.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIST_LENGHT 500

/*
@struct no
@brief Estrutura que guarda os conteúdos de cada arquivo e um inteiro que indica a próxima posição do arquivo.
*/
typedef struct __no_geral{
    char conteudo[60]; //conteudo do arquivo
    int prox_arq;
}no;


/*
@struct arquivo 
@brief Esta estrutura serve para salvar os metadados dos Arquivos (o nome, indice do primeiro bloco na outra lista e o numero total de bloco que este ocupa)
*/
typedef struct __arquivo{
    char nome_do_arquivo[30]; 
    int inicio; //marcando o inicio do arquivo
    int num_blocos; //tamanho do arquivo na lista
}arquivo;

#endif