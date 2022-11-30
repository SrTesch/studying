#include <stdio.h>
#include <stdlib.h>

struct Cars{
    int numChassi;
    char placa[7];
    char cor[10]    
};


void getCar(struct Cars *car){
    puts("Digite o número do Chassi:");
    scanf("%d", &car->numChassi);
    puts("Agora digite a placa do Carro:");
    scanf(" %s", &car->placa);
    puts("Agora digite a cor do carro:");
    scanf(" %s", &car->cor);
};

void imprimeCar(struct Cars *car){
    printf("O número do chassi é: %d\nA placa do carro é: %s\nA cor do carro é: %s\n", car->numChassi, car->placa, car->cor);
};

int main(){
    struct Cars *carro1;
    carro1 = (struct Cars*)malloc(sizeof(struct Cars));
    getCar(carro1);
    imprimeCar(carro1);
    return 0;
}