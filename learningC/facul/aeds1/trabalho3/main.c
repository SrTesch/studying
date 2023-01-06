#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(){
    no** lista = criarLista();

    int espacos_livres = MAX_LIST_LENGHT;
    int whatToDo = 1, alterados;

    arquivo ** lista_arq = malloc(sizeof(arquivo*) * 100); //número máximo de arquivos a serem inseridos


    while(whatToDo != 0){
        printf("\x1b[1;36m0- Sair\n1 - Inserir um item novo na lista\n2 - Remover Arquivo\n3 - Buscar Arquivo\n4 - Imprimir lista inteira\n5 - Buscar termo\n");
        scanf("%d", &whatToDo);

        if(whatToDo == 1){
            alterados = ler_arq(lista, espacos_livres, lista_arq);
            espacos_livres -= alterados;
        }
        else if(whatToDo == 2){
            alterados = remover_arq(lista_arq, lista);
            espacos_livres += alterados;
        }
        else if(whatToDo == 3)
            imprimir_arq(lista_arq, lista);
        else if(whatToDo == 4)
            imprimir_lista(lista_arq, lista);
        else if(whatToDo == 5)
            buscar_termo(lista_arq, lista);
    }

}