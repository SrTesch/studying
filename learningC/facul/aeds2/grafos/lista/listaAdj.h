#include <stdio.h>
#include <stdlib.h>

typedef struct __no{
    int aresta;
    int peso;
    struct __no * prox;
}no;

void inicializa(no ** lista, int v);

void ler(no **lista, int a, int tipo);

void printaLis(no ** lis, int ver);

void verificaLoop(no ** lis, int ver);

int grauDoNoX(no ** lis, int x);

void imprimeGraus(no ** lis, int v);

void verificaIsolados(no ** lis, int v);

void regular(no ** lis, int v);

void verificaParalelas(no ** lis, int v);

int main();