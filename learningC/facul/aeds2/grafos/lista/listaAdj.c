#include <stdio.h>
#include <stdlib.h>

typedef struct __no{
    int aresta;
    struct __no * prox;
    int peso;
}no;

void inicializa(no ** lista, int v){
    for(int i = 0; i < v; i++)
        lista[i] = NULL;
}

void ler(no **lista, int a, int tipo){
    int ini, fim, peso;
    if(tipo == 1 || tipo == 3){
        for(int i = 0; i < a; i++){
            scanf("%d %d %d", &ini, &fim, &peso);
            no * new = (no *) malloc(sizeof(no));
            new->aresta = fim;
            new->peso = peso;
            new->prox = lista[ini-1];
            lista[ini-1] = new;
            if(tipo == 1){
                no * other = (no *)malloc(sizeof(no));
                other->prox = lista[fim-1];
                other->peso = peso;
                other->aresta = ini;
                lista[fim-1] = new;
            }
            new = NULL;
        }
    }else{
        for(int i = 0; i < a; i++){
            scanf("%d %d", &ini, &fim);
            no * new = (no *) malloc(sizeof(no));
            new->aresta = fim;
            if(lista[ini-1] == NULL)
                lista[ini-1] = new;
            else{
                new->prox = lista[ini-1];
                lista[ini-1] = new;
            }
            if(tipo == 0){
                no * other = (no *)malloc(sizeof(no));
                other->aresta = ini;
                if(lista[fim-1] == NULL)
                    other->prox = lista[fim-1];
                else{
                    new->prox = lista[fim-1];
                    lista[fim-1] = new;
                }
                printf("Inseriu o no %d\n", i);
            }
            new = NULL;
        }
    }
}

void printaLis(no ** lis, int ver){
    no * x;
    for(int i = 0; i < ver; i++){
        x = lis[i];
        printf("%d: %d ", i+1, x->aresta);
        while(x->prox != NULL){
            x = x->prox;
            printf("%d ", x->aresta);
        }
        puts("");
    }
}

void verificaLoop(no ** lis, int ver){
    no * x;
    int total;
    for(int i = 0; i < ver; i++){
        x = lis[i];
        while(x->prox != NULL){
            if(x->aresta == i)
                printf("O vértice %d, possui um loop", i+1);
            x = x->prox;
        }
    }
}

int grauDoNoX(no ** lis, int x){
    int cont = 1;
    no * y;
    if(lis[x] == NULL){
        return 0;
    }else{
        y = lis[x];
        while(y->prox != NULL)
            cont++;
    }
}

void imprimeGraus(no ** lis, int v){
    int grau, max, min;
    grau = grauDoNoX(lis, 0);
    max = grau;
    min = min;
    printf("Vértice 1 tem grau %d\n", grau);
    for(int i = 1; i < v; i++){
        grau = grauDoNoX(lis, i);
        printf("Vértice %d tem grau %d\n", i+1, grau);
    }
    puts("");
    printf("Gráu máximo: %d\n", max);
    printf("Gráu minimo: %d\n", min);
}

void verificaIsolados(no ** lis, int v){
    int total = 0;
    int isolados[v];
    for(int i = 0; i < v; i++){
        isolados[i] = 0;
        if(grauDoNoX(lis, i) == 0){
            isolados[i] = 1;
            total++;
        }
    }
    if(total == 0)
        printf("Não há vértices isolados\n");
    else{
        printf("Os vértices abaixo são isolados:\n");
        for(int i = 0; i < v; i++){
            if(isolados[i]== 1)
                printf("%d ", i+1);
        }
        printf("Total: %d\n", total);
    }
}

void regular(no ** lis, int v){
    int grau = grauDoNoX(lis, 0);
    int i;
    for(i = 0; i < v; i++){
        if(grau != grauDoNoX(lis, i)){
            printf("Grafo não Regular\n");
            break;
        }
    }
    if(i == v){
        printf("Grafo regular\n");
    }
}

void verificaParalelas(no ** lis, int v){
    puts("");
    int total = 0, paralelas[v];
    for(int i = 0; i < v; i++){
        paralelas[i] = 0;
        int atual[v];

    }
}

int main(){
    int ver, arestas, tipo;
    scanf("%d %d %d", &ver, &arestas, &tipo);
    no * lista[ver];
    inicializa(lista, ver);
    ler(lista, arestas, tipo);
    printaLis(lista, ver);
    verificaLoop(lista, ver);
    imprimeGraus(lista, ver);
    verificaIsolados(lista, ver);
    return 0;
}