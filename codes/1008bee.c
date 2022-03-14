/*
Salário

Escreva um programa que leia o número de um funcionário,
seu número de horas trabalhadas, o valor que recebe por hora e
calcula o salário desse funcionário.
A seguir, mostre o número e o salário do funcionário, com duas casas decimais.

Entrada
O arquivo de entrada contém 2 números inteiros e 1 número com duas casas
decimais, representando o número, quantidade de horas trabalhadas e o
valor que o funcionário recebe por hora trabalhada, respectivamente.

Saída
Imprima o número e o salário do funcionário, conforme exemplo fornecido,
com um espaço em branco antes e depois da igualdade.
No caso do salário, também deve haver um espaço em branco após o $.

Exemplo 1 de Entrada:
25
100
5.50

Exemplo 1 de Saída:
NUMBER = 25
SALARY = U$ 550.00

Exemplo 2 de Entrada:
1
200
20.50

Exemplo 2 de Saída:
NUMBER = 1
SALARY = U$ 4100.00
*/

#include <stdio.h>
 
int main() {
    int a, b;
    double c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%lf", &c);
    double salario = b*c;
    printf("NUMBER = %d\n", a);
    printf("SALARY = U$ %.2lf\n", salario);
    return 0;
}
