#include <stdio.h>

int main(){
    int num, aux, aux2;
    printf("Digite o tamanho do seu quadrado: \n");
    scanf("%d", &num);
    aux2 = num;


    while(num != 0){
        aux = aux2;
        while(aux != 0){
            printf("* ");
            aux--;
        }
        num--;
        puts("");
    }

    return 0;
}