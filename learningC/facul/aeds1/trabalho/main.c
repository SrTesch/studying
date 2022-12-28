#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


int main(){
    char file_name[30];

    lista nova_lista;
    nova_lista.cab = NULL;
    nova_lista.ret = NULL;
    nova_lista.tam = 0;

    int whatToDo = 1;
    while(whatToDo != 0){
        printf("0- Sair\n1- Inserir um item novo na lista\n2- Buscar arquivo\n3- Buscar termo específico\n 4- Remover arquivo\n5- Imprimir toda a lista\n");
        scanf("%d", &whatToDo);

        if(whatToDo == 1)
            leitura(&nova_lista);
        else if(whatToDo == 2)
            imprimir_arq(&nova_lista);
        else if(whatToDo == 3)
            buscar_termo(&nova_lista);
        else if(whatToDo == 4)
            remover_arq(&nova_lista);
        else if(whatToDo == 5)
            imprimir_lista(&nova_lista);
        
    }
}