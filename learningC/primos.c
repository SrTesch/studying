#include <stdio.h>

int main(){
    int a, b, i;
    scanf("%d %d", &a, &b);
    a = a%b;
    /*
    if(a == 0 || a == 1){
        printf('Não são primos entre si');
    }else{
        for(i = 2; i < a; i++){
            if(a%i == 0 && b%i == 0){
                printf("Não são primos de novo");
            } else {
                printf("são primos");
            }
        }
    }
    */
   
    return 0;
}