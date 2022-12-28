#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


void gotoxy(int x,int y); // esta função serve pra alterar a posição do cursor no terminal, possibilitando certas costumizações no menu

noGeral *criarLista();

noGeral *inserir(noGeral *atual, char *text, char *nome_arq);

void inserir_arq(noGeral *inicio);

noGeral *end_arq(noGeral *inicio, char *nome_arq);

void remover_arq(noGeral *inicio);

void imprimir_arq(noGeral *inicio);

void imprimir_lista(noGeral *inicio);   