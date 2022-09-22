#include <stdio.h>

int sum(int *vet, int tamanho, int soma){
    if (tamanho == 0){
        return soma;
    }else{
        soma += *vet;
        tamanho -=1;
        return sum(vet+1,tamanho, soma);
    }
}

int main(){
    int vet[6] = {1,2,3,4,5,6}, x;
    x = sum(vet, 6, 0);
    printf("%d\n", x);
    return 0;
}