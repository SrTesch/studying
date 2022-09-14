#include <stdio.h>
#include <math.h>

int main(){
    int x, square, i, count = 0;
    scanf("%d", &x);
    square = ceil(sqrt(x));
    for(i = 2; i < square; i++){
        if(x%i == 0){
            count++;
            break;
        }
    }
    if(count != 0){
        printf("%d não é um número primo\n", x);
    }else{
        printf("%d é primo!\n", x);
    }
    return 0;
}