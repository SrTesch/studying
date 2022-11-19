#include <stdio.h>

int add(int, int);

int main(){
    int m = 20, n = 30, sum; /*esses são os argumentos*/
    sum = add(m,n);
    printf("a soma é %d\n", sum);

}

int add(int a, int b){ /*Aqui são os parametros*/
    return(a+b);
}

/*quis trazer esse cara só pra mostrar que tem como declarar uma função sem especifica-la (lin3)  e só depois de ser chamada, definir o que ela vai fazer