#include <stdio.h>

void inicializa(int v, int matriz[v][v]){
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            matriz[i][j] = 0;
        }
    }
}
void iniciaELe(int vertices, int arestas, int tipo, int matriz[vertices][vertices], int matrizPonderada[vertices][vertices]){
    inicializa(vertices, matriz);
    
    if(tipo == 0){
        int x = 0, inicio, fim;
        while (x < arestas){
            scanf("%d %d", &inicio, &fim);
            matriz[inicio-1][fim-1]++ ;
            matriz[fim-1][inicio-1]++;
            x++;
        }
    }else if(tipo == 1){
        int x = 0, inicio, fim, peso;
        //criando matriz para guardar os pesos de cada aresta
        inicializa(vertices, matrizPonderada);

        while (x < arestas){
            scanf("%d %d %d", &inicio, &fim, &peso);
            matriz[inicio-1][fim-1]++;
            matriz[fim-1][inicio-1]++;
            matrizPonderada[inicio-1][fim-1] = peso;
            matrizPonderada[fim-1][inicio-1] = peso;
            x++;
        }
    }else if(tipo == 2){
        int x = 0, inicio, fim;
        while (x < arestas){
            scanf("%d %d", &inicio, &fim);
            matriz[inicio-1][fim-1]++;
            x++;
        }
    }else if(tipo == 3){
        int x = 0, inicio, fim, peso;
        inicializa(vertices, matrizPonderada);
        while (x < arestas){
            scanf("%d %d %d", &inicio, &fim, &peso);
            matriz[inicio-1][fim-1]++;
            matrizPonderada[inicio-1][fim-1] = peso;
            x++;
        }
    }
}

void imprimaMatriz(int vertices, int matriz[vertices][vertices]){
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            printf("%d", matriz[i][j]);
        }
        puts("");
    }
}

void loop(int v, int matriz[v][v]){
    puts("");
    int x = 0;
    for(int i = 0; i < v; i++){
        if(matriz[i][i] != 0){
            printf("No vértice %d há um loop\n", i+1);
            x++;
        }
    }
    if(x == 0)
        puts("Não há loops");
}

int grauDoNoX(int vertices, int matriz[vertices][vertices], int x){
    int contador = 0;
    for(int i = 0; i < vertices; i++){
        contador+= matriz[x][i];
    }
    return contador;
}

void imprimeGraus(int vertices, int matriz[vertices][vertices]){
    puts("");
    int retorno, max, min;
    for(int i = 0; i < vertices; i++){
        retorno = grauDoNoX(vertices, matriz, i);
        printf("Vértice %d tem grau: %d\n", i+1, retorno);

        if(i == 0){
            max = retorno;
            min = retorno;
        }
        if(retorno > max)
            max = retorno;
        else if(retorno < min)
            min = retorno;
    }
    puts("");
    printf("Gráu máximo: %d\n", max);
    printf("Gráu mínimo: %d\n", min);
}

void imprimePesos(int v, int matriz[v][v]){
    puts("");
    int contador, maior, menor;
    for(int i = 0; i < v; i++){
        contador = 0;
        for(int j = 0; j < v; j++){
            contador+= matriz[i][j];
        }
        printf("Vértice %d tem peso %d\n", i+1, contador);
    }
}

void verificaParalelas(int v, int matriz[v][v]){
    puts("");
    int contador = 0;
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            if(matriz[i][j] > 1 && i != j){
                contador++;

                printf("Neste grafo há arestas paralelas entre os vértices %d e %d\n", i+1 , j+1);
            }
        }
    }
    if(contador == 0){
        printf("Não há arestas paralelas\n");
    }
}

void verificaIsolados(int v, int matriz[v][v]){
    puts("");
    int cont, total = 0, isolados[v];
    for(int i = 0; i < v; i++){
        cont = 0;

        for(int j = 0; j < v; j++){
            cont+= matriz[i][j];
        }

        if(cont == 0){
            total++;
            isolados[i] = 1;
        }else
            isolados[i] = 0;
    }
    if(total != 0){
        puts("Os vértices abaixo são isolados");
        for(int i = 0; i < v; i++){
            if(isolados[i] == 1){
                printf("%d\n", i+1);
            }
        }
        printf("total: %d\n", total);
    }else
        puts("Não há vertices isolados");
}

void isFull(int v, int matriz[v][v]){
    int retorno, full = 1;
    for(int i = 0; i < v; i++){
        retorno = grauDoNoX(v, matriz, i);
        if(retorno < v){
            full = 0;
            break;
        }
    }
    
    if(full == 0)
        puts("Grafo não completo");
    else
        puts("Grafo completo");
}

void regularidade(int v, int matriz[v][v]){
    int retorno, full = 1, last, i;
    for(i = 0; i < v; i++){
        retorno = grauDoNoX(v, matriz, i);
        if(i == 0)
            last = retorno;

        if(retorno != last){
            puts("Grafo não regular");
            break;
        }
    }
    if(i == v)
        puts("Grafo Regular");
}

int main(){
    int vertices, arestas, tipo;
    scanf("%d %d %d", &vertices, &arestas, &tipo);
    int matriz[vertices][vertices];
    int matrizPonderada[vertices][vertices];
    //incialização
    iniciaELe(vertices, arestas, tipo, matriz, matrizPonderada);
    imprimaMatriz(vertices, matriz);
    loop(vertices, matriz);
    verificaParalelas(vertices, matriz);
    verificaIsolados(vertices, matriz);
    // grauDoNoX(vertices, matriz, x);
    imprimeGraus(vertices, matriz);
    puts("");
    if(tipo == 1 || tipo == 3)
        imprimePesos(vertices, matrizPonderada);

    isFull(vertices, matriz);
    regularidade(vertices, matriz);
    return 0;
}


/*
criar / alocar (inicializar com zeros)
ler arquivo e inserir na matriz
imprimir matriz
imprimir grau de um nó v
imprimir grau de todos os nós

formato do arquivo:
onde z é o tipo de grafo:
z == 0 {é pq nao é direcionado nem pondedado}
z == 1 {nao é direcionado mas é ponderado}
z == 2 {é direcionado mas nao ponderado}
z == 3 {é direcionado e ponderado}
onde x é o numero de vértices
onde y é o numero de arestas
x y z
*/
