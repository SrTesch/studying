#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


void gotoxy(int x,int y); // esta função serve pra alterar a posição do cursor no terminal, possibilitando certas costumizações no menu

void enterVoltar(); //esta função serve pra pessoa apertar enter quando quiser voltar para o menu principal

no **criarLista();

int inserir(int inicio, char *text, no ** lista);

int ler_arq(no **inicio, int espaços_livres, arquivo ** lista_arq);

int end_arq(arquivo ** lista_arq, char arq);

int remover_arq(arquivo ** lista_arq, no **lista);

void imprimir_arq(arquivo ** lista_arq, no **lista);

void imprimir_lista(arquivo ** lista_arq, no ** lista);  