#include <stdio.h>
 
int main() {
    int x, y, maior, menor, sum = 0;
    scanf("%d %d", &x, &y);
    if(x >= y){
        maior = x;
        menor = y;
    }else{
        maior = y;
        menor = x;
    }

    if(menor%2 == 0){
        menor +=1;
    }else{
        menor +=2;
    }
    while(menor < maior){
        sum+= menor;
        menor +=2;
    }
    printf("%d\n", sum);
    return 0;
}