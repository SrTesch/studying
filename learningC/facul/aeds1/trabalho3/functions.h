#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


void gotoxy(int x,int y); // esta função serve pra alterar a posição do cursor no terminal, possibilitando certas costumizações no menu

void enterVoltar(); //esta função serve pra pessoa apertar enter quando quiser voltar para o menu principal

no *criarLista();

no *inserir(no *atual, char *text, char *nome_arq);

int ler_arq(no *inicio, int espaços_livres);

no *end_arq(no *inicio, char *nome_arq);

int remover_arq(no *inicio);

void imprimir_arq(no *inicio);

void imprimir_lista(no *inicio);   