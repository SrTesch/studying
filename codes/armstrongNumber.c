/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

tive que abandonar a ideia pq pensei numa solução mais plausível e paupável

int potencia(int base, int expoente){ 
    if(expoente == 0){
        return 1;
    }else{
        return (base * potencia(base, expoente-1));
    }
}

int main(char b[]){
    int i, cont = strlen(b),  valorTotal = atoi(b);
    int result[cont], aux, aux2 = 0;
    char valorUnit[20];

    for(i = 0; i < cont; i++){
        valorUnit[i] = b[i];
        aux = atoi(valorUnit);
        result[i] = potencia(aux, cont);
    }

    for(i = 0; i < cont; i++){
        aux2 += result[i];
    }

    if(valorTotal == aux2){
        printf("%d is an Armstrong number", valorTotal);
    }else{
        printf("%d is not an Armstrong number", valorTotal);
    }

    return 0;
}

*/

#include <stdbool.h>
#include <stdio.h>
#include <math.h>

bool isArmstrongNumber(int number){
  int exponent;
  int final = number;
  int sum = 0;
  exponent = floor(log10(number) + 1);
  while (number > 0) {
    int digit = number % 10;
    sum = sum + pow(digit, exponent);
    number /= 10; 
  }
  return sum == final;
}
