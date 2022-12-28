#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


void gotoxy(int x,int y); // esta função serve pra alterar a posição do cursor no terminal, possibilitando certas costumizações no menu

noGeral* criarLista();

void inserir(noGeral *atual, char *text, char *nome_arq);