#include <stdio.h>
#include <stdlib.h>

typedef struct noAVL{
    int cont;
    int FB;
    noAVL pai;
    noAVL esq;
    noAVL dir;
}noAVL;

void insertNode(noAVL * tree){
    system("clear");
    printf("Digite o número que deseja inserir:");
    int new;
    scanf("%d", &new);
    insert(new, tree);
    return;
}

void insert(int new, noAVL * tree){
    if(tree->cont == NULL)//neste caso, estamos numa lista vazia
        tree->cont =  new;
    else if(tree->cont > new){
        if(tree->esq != NULL)
            insert(new, tree->esq);
        else{
            tree->esq->cont = new;
            tree->esq->pai = tree;
        }
    }else if(tree->cont < new){
        if(tree->dir != NULL)
            insert(new, tree->dir);
        else{
            tree->dir->cont = new;
            tree->dir->pai = tree;
        }
    }else
        printf("Este número já foi inserido!\n");
    return;
}

int main(){
    noAVL * newTree;
    newTree = (noAVL *) malloc(sizeof(noAVL));
    int x = 1;
    while(x != 0){
        system("clear");
        printf("Olá, digite a opção desejada! \n (0)Sair\n (1)Inserir um novo nó\n (2)Remover um nó\n (3)Buscar um nó\n");
        scanf("%d", &x);
        if(x == 1)
            insertNode(newTree);
    }
}