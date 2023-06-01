#include "listaAdj.h"

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
            new->prox = NULL;
            if(lista[ini-1] == NULL)
                lista[ini-1] = new;
            else{
                new->prox = lista[ini-1];
                lista[ini-1] = new;
            }
            if(tipo == 0){
                no * new = (no *) malloc(sizeof(no));
                new->aresta = ini;
                new->prox = NULL;
                if(lista[fim-1] == NULL)
                    lista[fim-1] = new;
                else{
                    new->prox = lista[fim-1];
                    lista[ini-1] = new;
                }
                printf("Inseriu a aresta %d\n", i);
            }
            new = NULL;
        }
    }
}

void printaLis(no ** lis, int ver){
    no * x;
    for(int i = 0; i < ver-1; i++){
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
    for(int i = 0; i < ver-1; i++){
        x = lis[i];
        int why = 0;
        while(x->prox != NULL){
            why++;
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
        while(y->prox != NULL){
            cont++;
            y = y->prox;
        }
        return cont;
    }
}

void imprimeGraus(no ** lis, int v){
    int grau, max, min;
    grau = grauDoNoX(lis, 0);
    printf("Grau do no 1: %d\n", grau);
    max = grau;
    min = grau;
    for(int i = 1; i < v-1; i++){
        grau = grauDoNoX(lis, i);

        if(grau > max)
            max = grau;
        else if(grau < min)
            min = grau;

        printf("Vértice %d tem grau %d\n", i+1, grau);
    }
    puts("");
    printf("Gráu máximo: %d\n", max);
    printf("Gráu mínimo: %d\n", min);
}

void verificaIsolados(no ** lis, int v){
    int total = 0;
    int isolados[v-1];
    for(int i = 0; i < v-1; i++){
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
    verificaIsolados(lista, ver);
    imprimeGraus(lista, ver);
    return 0;
}
