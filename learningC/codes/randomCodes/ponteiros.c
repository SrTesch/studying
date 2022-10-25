#include <stdio.h>

int main(){
    int valor = 27;

    int *ptr;

    ptr = &valor;

    printf("Utilizando ponteiros\n\n");
    printf("Conteudo da variavel valor: %d\n", valor);
    printf("Endereço da variavel valor: %x\n", &valor);
    printf("Conteúdo da variavel ponteiro ptr: %x", ptr);

    return 0;
}