#include "listaAdj.h"

void inicializa(no ** lista, int v){
    puts("Oi to inicializando");
    no * new = (no *) malloc(sizeof(no));
    new->aresta = 0;
    new->prox = NULL;
    for(int i = 0; i < v; i++){
        lista[i] = new;
        printf("Criei o nó-> %d\n", i);
    }
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
            if(lista[ini-1]->aresta == 0)
                lista[ini-1] = new;
            else{
                new->prox = lista[ini-1];
                lista[ini-1] = new;
            }
            if(tipo == 0){
                no * new = (no *) malloc(sizeof(no));
                new->aresta = ini;
                new->prox = NULL;
                if(lista[fim-1]->aresta == 0)
                    lista[fim-1] = new;
                else{
                    new->prox = lista[fim-1];
                    lista[fim-1] = new;
                }
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
    int total = 0;
    for(int i = 0; i < ver; i++){
        x = lis[i];
        while(x->prox != NULL){
            if(x->aresta == i){
                printf("O vértice %d, possui um loop\n", i+1);
                total++;
            }
            x = x->prox;
        }  
    }
    if (total != 0)
        printf("Total: %d\n", total);
    else
        puts("Não há loops");
}

int grauDoNoX(no ** lis, int x){
    int cont = 1;
    no * y;
    if(lis[x]->aresta == 0){
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
    printf("Vértice 1 tem grau %d\n", grau);
    max = grau;
    min = grau;
    for(int i = 1; i < v; i++){
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
        printf("\nTotal: %d\n", total);
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
    puts("");
    verificaLoop(lista, ver);
    puts("");
    verificaIsolados(lista, ver);
    puts("");
    imprimeGraus(lista, ver);
    return 0;
}
