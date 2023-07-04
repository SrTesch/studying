#include <stdio.h>
#include <stdlib.h>

#include "../lista/listaAdj.h"



void BFS(no ** grafo, int inicio){
    
}

int main(){

    int ver, arestas;
    scanf("%d %d", &ver, &arestas);
    no * grafo[ver];
    inicializa(grafo, ver);

    BFS(grafo, ver);

    return 0;
}