/*
Questao 1020 do bee crowd em que devo criar um programa em que o
usuário digita um valor que representa dias e tenho que mostrar o
correspondente em anos.
*/

#include <stdio.h>
 
int main() {
    int n, anos, meses, dias;
    scanf("%d", &n);
    anos= n/365;
    meses = (n-(anos*365))/30;
    dias = (n-(meses*30)-(anos*365));
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias);
    return 0;
}
