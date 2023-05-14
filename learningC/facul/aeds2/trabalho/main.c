#include <stdio.h>
#include <stdlib.h>
#include "src/arvore/arvore.h"
#include "src/lista/lista.h"


int main(){
    noAVL * raiz;

    int operand = 0;

    while(operand != 6){
        printf("*** MENU DE OPÇÕES: ENTRE COM A OPÇÃO DESEJADA ***\n\n");
        printf("1. Pesquisa\n2. Inserção\n3. Remoção\n4. Impressão de um nó\n5. Impressão da árvore\n6. Encerrar\n\n");
        scanf("%d", &operand);

        switch (operand)
        {
        case 1: //busca
            printf("Eu sou lindo\n");
            break;
        case 2: //inserção
            int t = inserir(&raiz);
            printf("Total de %d palavras inseridas no dicionário\n\n", t);
            break;
        case 3: //remoção
            printf("Eu sou lindo\n");
            break;
        case 4: //printf nas palavras de um determinado nó 
            printf("Eu sou lindo\n");
            break;
        case 5: //imprime tudo
            printf("5\nImprimindo Árvore...\n\n");
            break;
        default:
            printf("6\nPrograma Encerrado!!");
            break;
        }
    }
    return 0;
}