//Códigos feito, organizado, refatorado e testado por ninguém mais ninguém menos que Pedro Tesch e Stefanni Kapps

#include <math.h>
#include <stdio.h>

int main(){
    int x, n, aux, i;
    scanf("%d %d", &x, &n);
    aux = x; //guardando o valor de X
    x = x % n; //tranformando o x em algum numero dentro de Zn
/*------------------------------*/
    if(x == 0 || x == 1){
        printf("Este valor %d não possui inverso em Z%d.\n", aux, n); //pois não são primos entre si
        return 0;
    }else{
        for(i = 2; i < x; i++){
            if(x%i == 0 && n%i == 0){
                printf("Este valor %d não possui inverso em Z%d.\n", aux, n); //pois não são primos entre si
                return 0;
        }
    }

    for (int i = 0; i < n; i++){
        if(((x*i)%n) == 1){ 
        printf("O inverso de %d em Z%d é %d.\n", aux, n, i);
        break;
        }
    }
    return 0;
    }
}