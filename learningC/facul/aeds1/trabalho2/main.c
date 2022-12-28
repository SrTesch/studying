#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(){
    noGeral *inicio = criarLista();

    int whatToDo = 1;
    while(whatToDo != 0){
        printf("0- Sair\n1 - Inserir um item novo na lista\n2 - Remover Arquivo\n3 - Buscar Arquivo\n");
        scanf("%d", &whatToDo);

        if(whatToDo == 1)
            inserir_arq(&inicio);
        else if(whatToDo == 2)
            remover_arq(&inicio);
        else if(whatToDo == 3)
            imprimir_arq(&inicio);
    }
}