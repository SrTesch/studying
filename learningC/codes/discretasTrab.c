/* 
Os bem feitores dessa linda obra de arte são:
Pedro Tesch e Stefanni Kapps
*/

#include <stdio.h>


// MDC  

int main(){   
    int a, b, dividendo, divisor, resto, aux, mult, mmc;
    printf("Digite o valor do dividendo: ");
    scanf("%d",&dividendo);
    printf("Digite o valor do divisor: ");
    scanf("%d",&divisor);
    
    if (divisor > dividendo){
        aux = dividendo;
        dividendo = divisor;
        divisor = aux;
    }
    
    a = dividendo;
    b = divisor;
    
    do{
        resto = a%b;
        a = b;
        b = resto ;
    }
    while(b != 0);
    
    printf("O valor do MDC entre %d e %d é igual a %d\n",dividendo, divisor,a);
    
    if (a == 1){
        printf("São primos entre si\n");
    }
    else{
        printf("Não são primos entre si\n");
    }

// MMC 
    
    mult = dividendo * divisor;
    mmc = mult/a; 
    printf("E seu mmc é %d", mmc);
   
    return 0;
}
