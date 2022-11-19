#include <stdio.h>

int main(){
    int x, i;
    scanf("%d", &x);
    if(x%2 != 0){

        for(i = 0; i < 6; i++){
            printf("%d\n", x);
            x += 2;
        }
    }else{
        x +=1;
        for(i = 0; i < 6; i++){
            printf("%d\n", x);
            x += 2;
        }
    }
    return 0;
}