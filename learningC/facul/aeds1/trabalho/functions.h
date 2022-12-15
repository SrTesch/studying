#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void inserirFim(lista *lista, char *valor, char *name);
// eu sou lindo

void leitura(lista *lista, char *arq);
// serhse

void imprime(lista *lista);

conteudo_buscado *busca(lista *lista, char *arq);

void buscar_arq(lista *lista, char *arq);

void remove_arq(lista *lista, char *arq);
// essa função 

lista* criar_lista();