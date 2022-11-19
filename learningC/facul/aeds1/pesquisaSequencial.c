#include <stdio.h>

int buscaSeq(int n, int vetor[], int chave){
    int i;
    for(i = 0; i < n; i++){
        if(vetor[1] == chave){
            return i;
        }
    }
    return -1;
}