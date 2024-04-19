#include <stdio.h>
/*
int swap(int x, int y){
    int aux;
    aux = x;
    x = y;
    y = aux;
    int vetor = [2];
    vetor[0] = x;
    vetor[1] = y;
    return vetor;
}
*/

int main(){
    int a, b, c;
    puts("Digite 3 valores diferentes separados por espaço:");
    scanf("%d %d %d", &a, &b, &c);

    int aux;

    while(a < b || a < c || b < c){

        if(a < b){
            aux = b;
            b = a;
            a = aux;
        }  

        if(b < c){
            aux = c;
            c = b;
            b = aux;

        }
    }

    if(a >= b + c ){
        puts("Triangulo impossível!!");
    }else if(a*a ==  b*b + c*c){
        puts("triangulo retangulo");
    }else if(a*a >  b*b + c*c){
        puts("triangulo obtusangulo");
    }else if(a*a <  b*b + c*c){
        puts("triangulo acutangulo");
    }else if(a ==  b && a == c){
        puts("triangulo equilatero");
    }else if(a == b || a == c || b == c ){
        puts("triangulo retangulo");
    }

    return 0;
}