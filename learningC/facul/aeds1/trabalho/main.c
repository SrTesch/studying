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

    printf("Digite o nome do arquivo que voce deseja inserir: ");
    scanf("%s", file_name);
    leitura(&nova_lista, file_name);
    puts("Digite o nome do arquivo que voce quer achar:");
    scanf("%s", file_name);
    buscar_arq(&nova_lista, file_name);
    printf("tamanho da lista => %d\n", nova_lista.tam);

    puts("REMOVE AI PORRA");
    scanf("%s", file_name);
    remove_arq(&nova_lista, file_name);
    printf("tamanho da lista => %d\n", nova_lista.tam);
}