#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


void gotoxy(int x,int y); // esta função serve pra alterar a posição do cursor no terminal, possibilitando certas costumizações no menu

void enterVoltar(); //esta função serve pra pessoa apertar enter quando quiser voltar para o menu principal

noGeral *criarLista();

noGeral *inserir(noGeral *atual, char *text, char *nome_arq);

int ler_arq(noGeral *inicio, int espaços_livres);

noGeral *end_arq(noGeral *inicio, char *nome_arq);

int remover_arq(noGeral *inicio);

void imprimir_arq(noGeral *inicio);

void imprimir_lista(noGeral *inicio);   