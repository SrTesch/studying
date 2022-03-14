#include <stdio.h>

int main(){
    
    int a=0,g=0,d=0,x;
    while(x!=4){
        scanf("%d", &x);
        if(x==1){
            a+=1;
        }else if(x==2){
            g+=1;
        }else if(x==3){
            d+=1;
        }
    }
    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n", a);
    printf("Gasolina: %d\n", g);
    printf("Diesel: %d\n", d);
    return 0;
}
