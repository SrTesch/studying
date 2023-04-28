#include <stdio.h>
#include <stdlib.h>

typedef struct __no{
    int peso; //para quando o grafo for ponderado...
    int conteudo;
    struct __no * numAresta;
}no;

int main(){
    puts("Olá, seja bem vindo à sua lista de adjacência");
}