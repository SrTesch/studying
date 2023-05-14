#include <stdio.h>
#include <stdlib.h>

#include "lista/listaAdj.h"

/*
Para cada iteração:
    distância {entre o nó e a raiz}
    predecessor {quem é o seu anterior na "árvore"}
    cor {B, P, C}
    fila {Estado da fila naquele momento}
*/

void BFS(no ** grafo, int inicio){
    int d[0] = 0;
    for(int i = 0; i < inicio; i++){

    }
}

int main(){

    int ver, arestas;
    scanf("%d %d", &ver, &arestas);
    no * grafo[ver];

    BFS(grafo, ver);


    return 0;
}