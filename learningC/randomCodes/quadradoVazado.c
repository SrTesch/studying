#include <stdio.h>

int main(){
    int qtd;

    printf("Insira um número para formar um quadrado vazado: ");
    scanf("%d",&qtd);

    for(int i = 0; i < qtd; i++){
        for(int j = 0; j < qtd; j++){
            if(i == 0 || i == qtd-1)
                printf("*");
            else if(j == 0 || j == qtd-1)
                printf("*");
            else
                printf(" ");
        }
        puts("");
    }
}
