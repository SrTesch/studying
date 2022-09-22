#include <stdio.h>

int doubleFat(int x){
    if(x == 0 || x == 1){
        return 1;
    }else{
        return x * doubleFat(x-2);
    }
}

int main(){
    int x;
    printf("Digite o número (ímpar) para retornarmos o fatorial duplo do próprio:");
    scanf("%d", &x);
    x = doubleFat(x);
    printf("%d\n", x);
    return 0;
}