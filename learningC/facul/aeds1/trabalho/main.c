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
        printf("0- Sair\n1- Inserir um item novo na lista\n2- Buscar arquivo\n3- Remover arquivo\n4- Imprimir toda a lista\n");
        scanf("%d", &whatToDo);

        if(whatToDo == 1){
            
            char nome_do_arquivo[30];
            printf("Digite o nome do arquivo que deseja inserir: ");
            scanf("%s", nome_do_arquivo);
            
            leitura(&nova_lista, nome_do_arquivo);
            printf("tamanho da lista => %d\n", nova_lista.tam);
        }else if(whatToDo == 2){
            char nome_do_arquivo[30];
            printf("Digite o nome do arquivo que deseja buscar: ");
            scanf("%s", nome_do_arquivo);

            imprimir_arq(&nova_lista, nome_do_arquivo);
            printf("tamanho da lista => %d\n", nova_lista.tam);
        }else if(whatToDo == 3){
            char nome_do_arquivo[30];
            printf("Digite o nome do arquivo que deseja remover: ");
            scanf("%s", nome_do_arquivo);
            remove_arq(&nova_lista, nome_do_arquivo);
            printf("tamanho da lista => %d\n", nova_lista.tam);
        }else if(whatToDo == 4){

            imprime(&nova_lista);
        }
    }
}