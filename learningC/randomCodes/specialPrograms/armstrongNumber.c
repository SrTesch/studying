#include <stdio.h>

int main(){
int x, aux, tamanho = 0, cnt, result = 0, mul = 1, resto;
scanf("%d", &x);
aux = x;
while(aux!=0){
    aux = aux/10;
    tamanho++;
}
cnt = tamanho;
aux = x;
while(aux != 0){
    resto = aux % 10;
    while(cnt!= 0){
        mul *= resto;
        cnt--;
    }
    result += mul;
    cnt = tamanho;
    aux = aux/10;
    mul = 1;
}

if(result == x){
    printf("%d é um número de Armstrong!", x);
}else{
    printf("%d não é um número de Armstrong", x);
}

return 0;
}