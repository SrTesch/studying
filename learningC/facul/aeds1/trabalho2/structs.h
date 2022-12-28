#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __no_geral{
    int indice;
    char nome_do_arquivo[30];
    char conteudo[60];
    struct __no_geral *prox;
    struct __no_geral *prox_arq;
}noGeral;