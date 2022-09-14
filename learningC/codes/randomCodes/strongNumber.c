#include <stdio.h>

int main(){
    int x, i, total = 0, ultimo, aux, fat = 1, dig;
    printf("Digite um número para saber se ele é um número forte:\n");
    scanf("%d", &x);
    aux = x; //Colocando esse cara aqui só pra nao perder o valor de x
    while(aux!= 0){
        ultimo = aux%10;
        dig = ultimo;
        for(i = 0; i < ultimo;i++){
            fat *= dig;
            dig--;
        }
        aux = aux/10;
        total += fat;
        fat = 1;
    }

    if(total == x){
        printf("%d é um número forte!\n", x);
    }else{
        printf("%d não é um número forte!\n", x);
    }
    return 0;
}