#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(){
    no *inicio = criarLista();
    int espaços_livres = MAX_LIST_LENGHT;
    int whatToDo = 1, alterados;
    while(whatToDo != 0){
        system("clear");
        printf("\x1b[1;36m0- Sair\n1 - Inserir um item novo na lista\n2 - Remover Arquivo\n3 - Buscar Arquivo\n4 - Imprimir lista inteira\n");
        scanf("%d", &whatToDo);

        if(whatToDo == 1){
            alterados = ler_arq(inicio, espaços_livres);
            espaços_livres -= alterados;
        }
        else if(whatToDo == 2){
            remover_arq(inicio);
            espaços_livres += alterados;
        }
        else if(whatToDo == 3)
            imprimir_arq(inicio);
        else if(whatToDo==4)
            imprimir_lista(inicio);
    }
}