#include <stdio.h>

int pesquisaBin(int n, int vetor[], int chave){
    int inf = 0, sup = n - 1, meio;
    while (inf <= sup){
        meio = (inf + sup) /2;
        if(chave == vetor[meio]){
            //chave encontrada
            return meio;
        }
        if (chave < vetor[meio])
        {
            sup = meio -1;
        }else{
            inf = meio +1;
        }
    }
    return -1; //chave não encontrada
    
}