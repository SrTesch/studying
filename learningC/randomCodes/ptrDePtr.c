#include <stdio.h>

int main(){
    int x, *ptrx, **pptrx;

    x = 0;
    printf("\nValor de x = %d\n", x);
    printf("Endereço de x: %x\n\n", &x);

    ptrx = &x;
    pptrx = &ptrx;


    *ptrx = *ptrx + 10;
    printf("Valor de x = %d\n", x);
    printf("Endereço apontado por ptrx: %x\n", ptrx);
    printf("Valor da variavel X: %d\n", *ptrx);
    printf("\nEndereço de memoria da variavael ptrx: %x\n", &ptrx);

    **pptrx = **pptrx + 10;
    printf("Valor de x = %d\n", x);
    printf("Endereço apontado por **pptrx: %x", pptrx);
    printf("Valor da Variavel para a qual pptrx faz referencia: %d", **pptrx);
    printf("Endereço da variavel **pptrx: %x", &pptrx);

    return 0;
}