#include <stdio.h>

int main(){
    int a, quant;
    double price, tot;
    scanf("%d%d", &a, &quant);
    if(a == 1){
        price = 4.0;
    }
    else if(a == 2){
        price = 4.5;
    }
    else if(a == 3){
        price = 5.0;
    }
    else if(a == 4){
        price = 2.0;
    }
    else{
        price = 1.5;
    }
    tot= price * quant;
    printf("Total: R$ %.2lf\n", tot);
    return 0;
}
