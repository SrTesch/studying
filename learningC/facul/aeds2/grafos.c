#include <stdio.h>

void iniciaELe(int vertices, int arestas, int tipo, int matriz[vertices][vertices], int matrizPonderada[vertices][vertices]){
        for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            matriz[i][j] = 0;
        }
    }
    
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
        for(int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices; j++){
                matrizPonderada[i][j] = 0;
            }
        }

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
        int matrizPonderada[vertices][vertices];
        //criando matriz para guardar os pesos de cada aresta
        for(int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices; j++){
                matrizPonderada[i][j] = 0;
            }
        }
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
    }
}

void grauDoNoX(int vertices, int matriz[vertices][vertices], int x){
    int contador;
    for(int i = 0; i < vertices; i++){
        contador+= matriz[x][i];
    }
    printf("Este nó tem grau: %d\n", contador);
    return;
}

void imprimeGraus(int vertices, int matriz[vertices][vertices]){
    int contador;
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){

        }
    }
    printf("\n");
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int vertices, arestas, tipo;
    scanf("%d %d %d", &vertices, &arestas, &tipo);
    int matriz[vertices][vertices];
    int matrizPonderada[vertices][vertices];
    //incialização
    iniciaELe(vertices, arestas, tipo, matriz, matrizPonderada);
    imprimaMatriz(vertices, matriz);
    int x = 2; //numero de exemplo
    grauDoNoX(vertices, matriz, x);
    imprimeGraus(vertices, matriz);
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
z == 0 {é pq nao é direcionado nem ponderdado}
z == 1 {nao é direcionado mas é ponderador}
z == 2 {é direcionado mas nao ponderado}
z == 3 {é direcionado e ponderado}
onde x é o numero de vértices
onde y é o numero de arestas
x y z
*/
