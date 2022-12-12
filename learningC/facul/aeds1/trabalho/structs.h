#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 80

typedef struct no{
    char file_name[30];
    char c[MAX_LINE_LENGTH];
    struct no *prox;
}no;

typedef struct lista{
    struct no *cab;
    struct no *ret;
    int tam;
}lista;
