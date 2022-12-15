#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 80
#define MAX_LENGHT 999

typedef struct __no{
    char nome_do_arquivo[30];
    char conteudo[MAX_LINE_LENGTH];
    struct __no *prox;
}no;

typedef struct lista{
    no *cab;
    no *ret;
    int tam;
}lista;

typedef struct conteudo_buscado{
    no *inicial;
    no *anterior;
    int tam;
}conteudo_buscado;