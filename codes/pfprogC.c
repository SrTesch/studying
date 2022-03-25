#include <stdio.h>
#include <stdlib.h>

int todosVisitados(int *array, int tam){
    int result = 1, i;
    for(i =0; i < tam; i++){
        if(array[i] == 0){
            result = 0;
            break;
        }
    }
    return result;
}

int getLinguaY(int index,int totalPessoas){
    return totalPessoas + index; 
}

void busca(int *visitados, int **matrizGeral, int totalVertice, int verticeAtual){
    int i;
    if(visitados[verticeAtual] == 0){
        visitados[verticeAtual] = 1;
        for(i = 0; i < totalVertice; i++){
            if(matrizGeral[verticeAtual][i] == 1){
                busca(visitados, matrizGeral, totalVertice, i);
            }
        }
    }
}

int buscaLingua1(int **matriz, int pessoa, int totalLing, int totalPessoas){
    int i;
    for(i =0; i < totalLing; i++){
        if(matriz[pessoa][getLinguaY(i, totalPessoas)]){
            return i;
        }
    }
    return -1;
}

void printandoMatriz(int **matriz, int totalVertice){
    puts(" ");
    for(int j = 0; j < totalVertice; j++){
        printf("\t%d", j);
    }
    printf("\n");
    for(int i = 0; i < totalVertice; i++){
        printf("%d", i);
        for(int j = 0; j < totalVertice; j++){
            printf("\t%d", matriz[i][j]);
        }
        printf("\n");
    }    
}

void printVisitdados(int *array, int totalFunc){
    int result = 1, i;
    printf("\nV");
    for(i =0; i < totalFunc; i++){
        printf("\t%d", array[i]);
    }
    printf("\n");
}


int linguaQualquer(int **matriz, int totalFunc, int pessoa, int totalLing){
    int result = -1, i, j;
    for(i =0; i < totalFunc; i++){
        if(i == pessoa){
            continue;
        }
        for(j = 0; j < totalLing; j++){
            if(matriz[i][getLinguaY(j, totalFunc)] != 0){
                result = getLinguaY(j, totalFunc);
                break;
            }
        }
        if(result ==getLinguaY(j, totalFunc))
        break;
    }
    
    
    return result;
}

int verifica(int **matriz,int totalVertice, int pessoa, int totalFunc, int totalLing){
    int indice;
    
    for(int i= 0; i < totalLing; i++){
        indice = getLinguaY(i, totalFunc);
        if(matriz[pessoa][indice]== 1){
            for(int j =0; j <totalFunc; j++){
                if(matriz[j][indice] == 1){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    int i, j, pos, totalFunc, totalLing, lingIndividuais, lingua, **matrizGeral, *visitados, totalVertice, cont = 0;
    scanf("%d %d", &totalFunc, &totalLing);
    totalVertice = totalFunc + totalLing;
    visitados = (int*) malloc((totalVertice) * sizeof(int));
    matrizGeral = (int**) malloc((totalVertice) * sizeof(int*));
    
    for(i =0; i < totalVertice; i++){
        matrizGeral[i] = (int*) malloc((totalVertice) * sizeof(int));
        visitados[i] = 0;
        for(j =0; j < totalVertice; j++){
            matrizGeral[i][j] = 0;
        }
    }

    for(i = 0; i < totalFunc; i++){
        scanf("%d", &lingIndividuais);
        matrizGeral[i][i] = 1;
        for(j =0; j < lingIndividuais; j++){
            scanf("%d", &lingua);
            matrizGeral[i][getLinguaY(lingua - 1, totalFunc)] = 1;
            matrizGeral[getLinguaY(lingua - 1, totalFunc)][i] = 1; 
        }
    }

    // printandoMatriz(matrizGeral, totalVertice);


    while(!todosVisitados(visitados, totalFunc)){
        for(i = 0; i < totalVertice; i++){
            visitados[i] = 0;
        }
        busca(visitados, matrizGeral, totalVertice, 0);
        //    printandoMatriz(matrizGeral,totalVertice);
        //    printVisitdados(visitados, totalFunc);
        //     getchar();
        if(!todosVisitados(visitados, totalFunc)){
            for(i = 0; i < totalFunc; i++){
                if(buscaLingua1(matrizGeral, i, totalLing, totalFunc) == -1){
                //    printf("%d\n",buscaLingua1(matrizGeral, i, totalLing, totalFunc));
                    visitados[i] = 0;
                }
                if(visitados[i] == 0){
                 //    printf("%d\n", i);
                    pos = linguaQualquer(matrizGeral, totalFunc, i, totalLing);
                    if(pos == -1){
                        matrizGeral[i][getLinguaY(0, totalFunc)] = 1;
                        matrizGeral[getLinguaY(0, totalFunc)][i] = 1;
                        cont++;
                        break;
                    }else{
                  //      printf("%d\n", pos);
                        if(matrizGeral[i][pos] == 0){
                            matrizGeral[i][pos] = 1;
                            matrizGeral[pos][i] = 1;
                            cont++;
                            break;
                        }
                    }
                }
            }
        }
    }
   // printandoMatriz(matrizGeral, totalVertice);
    printf("%d\n", cont);
    free(visitados);free(matrizGeral);
    return 0;
}