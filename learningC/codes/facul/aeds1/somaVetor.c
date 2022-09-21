#include <stdio.h>

int sum(int *vet, int tamanho, int soma){
    if (tamanho == 0){
        return soma;
    }else{
        soma += vet[tamanho];
        tamanho -=1;
        return sum(vet+1,tamanho, soma);
    }
    
}

int main(){
    int vet[4] = {1,2,3,4}, x;
    x = sum(vet, 4, 0);
    printf("%d\n", x);
    return 0;
}