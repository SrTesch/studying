#include <stdio.h>

int main(){
    int x;
    puts("Digite o tamanho da matriz que você quer:");
    scanf("%d", &x);
    
    for(int j = 0; j < x; j++){
        for(int i = 0; i < x; i++){
            printf("*");
        }
        printf("\n");
    }
    

    return 0;
}