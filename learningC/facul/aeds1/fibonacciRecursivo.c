#include <stdio.h>

int fib(int x){
    if(x == 1 || x == 2){
        return 1;
    }else{
        return fib(x-1) + fib(x-2);
    }
}

int main(){
    int x;
    printf("Digite o número que voce quer ver da sequencia de fibonacci:\n");
    scanf("%d", &x);
    x = fib(x);
    printf("%d\n", x);
    return 0;
}