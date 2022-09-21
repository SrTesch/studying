#include <stdio.h>

int invert(int x){
    int n;
    if(x == 0){
        return 0;
    }else{
        n = x%10;
        printf("%d", n);
        return invert(x/10);
    }
}

int main(){
    int x;
    printf("Digite um número:");
    scanf("%d", &x);
    printf("Este número ao contrário fica: \n");
    invert(x);
    printf("\n");
    return 0;
}