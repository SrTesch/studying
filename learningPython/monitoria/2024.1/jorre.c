#include <stdio.h>

int main(){
    int x;
    puts("Digite o tamanho da matriz que você quer:");
    scanf("%d", &x);
   
    int i = 0;
    while ( i < x){

        int j = 0;
        
        while (j< x ){
            printf("*");
            j += 1;
        }
        printf ("\n");
        i += 1;
    }



    return 0;
}