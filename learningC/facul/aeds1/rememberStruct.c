#include <stdio.h>
#include <stdlib.h>

typedef struct cars{
    int numChassi;
    char placa[8];
    char cor[10]; 
}cars;


void getCar(cars *car){
    puts("Digite o número do Chassi:");
    scanf("%d", &car->numChassi);
    puts("Agora digite a placa do Carro:");
    scanf(" %s", &car->placa);
    puts("Agora digite a cor do carro:");
    scanf(" %s", &car->cor);
};

void imprimeCar(cars *car){
    printf("O número do chassi é: %d\nA placa do carro é: %s\nA cor do carro é: %s\n", car->numChassi, car->placa, car->cor);
};

int main(){
    cars *carro1;
    carro1 = (cars*)malloc(sizeof(cars));
    getCar(carro1);
    imprimeCar(carro1);
    return 0;
}