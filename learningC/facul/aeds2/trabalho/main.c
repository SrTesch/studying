#include <stdio.h>
#include <stdlib.h>
#include "src/arvore/arvore.h"
#include "src/lista/lista.h"

int main(){
    noAVL * raiz;

    int operand = 0;

    while(operand != 6){
        scanf("%d", &operand);

        switch (operand)
        {
        case 1: //busca
            printf("Eu sou lindo\n");
            break;
        case 2: //inserção
            inserir(&raiz);
            break;
        case 3: //remoção
            printf("Eu sou lindo\n");
            break;
        case 4: //printf nas palavras de um determinado nó 
            printf("Eu sou lindo\n");
            break;
        case 5: //imprime tudo
            printf("Eu sou lindo\n");
            break;
        default:
            break;
        }
    }
    return 0;
}