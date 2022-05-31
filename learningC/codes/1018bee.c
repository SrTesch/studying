/*
Cédulas

Leia um valor inteiro. A seguir, calcule o menor número de notas possíveis
(cédulas) no qual o valor pode ser decomposto.
As notas consideradas são de 100, 50, 20, 10, 5, 2 e 1.
A seguir mostre o valor lido e a relação de notas necessárias.

Entrada
O arquivo de entrada contém um valor inteiro N (0 < N < 1000000).

Saída
Imprima o valor lido e, em seguida, a quantidade mínima de notas de cada
tipo necessárias, conforme o exemplo fornecido.
Não esqueça de imprimir o fim de linha após cada linha,
caso contrário seu programa apresentará a mensagem: “Presentation Error”.

Exemplo 1 de Entrada:
576

Exemplo 1 de Saída:
576
5 nota(s) de R$ 100,00
1 nota(s) de R$ 50,00
1 nota(s) de R$ 20,00
0 nota(s) de R$ 10,00
1 nota(s) de R$ 5,00
0 nota(s) de R$ 2,00
1 nota(s) de R$ 1,00

Exemplo 2 de Entrada:
11257

Exemplo 2 de Saída:
11257
112 nota(s) de R$ 100,00
1 nota(s) de R$ 50,00
0 nota(s) de R$ 20,00
0 nota(s) de R$ 10,00
1 nota(s) de R$ 5,00
1 nota(s) de R$ 2,00
0 nota(s) de R$ 1,00
*/


#include <stdio.h>
 
int main() {
    int a, cem, cinq, vinte, dez, cinco, dois, um;
    scanf("%d", &a);
    cem = a/100;
    cinq = (a-(cem*100))/50;
    vinte = (a-(cinq*50)-(cem*100))/20;
    dez = (a-(vinte*20)-(cinq*50)-(cem*100))/10;
    cinco = (a-(dez*10)-(vinte*20)-(cinq*50)-(cem*100))/5;
    dois = (a-(cinco*5)-(dez*10)-(vinte*20)-(cinq*50)-(cem*100))/2;
    um = (a-(dois*2)-(cinco*5)-(dez*10)-(vinte*20)-(cinq*50)-(cem*100));
    printf("%d\n", a);
    printf("%d nota(s) de R$ 100,00\n", cem);
    printf("%d nota(s) de R$ 50,00\n", cinq);
    printf("%d nota(s) de R$ 20,00\n", vinte);
    printf("%d nota(s) de R$ 10,00\n", dez);
    printf("%d nota(s) de R$ 5,00\n", cinco);
    printf("%d nota(s) de R$ 2,00\n", dois);
    printf("%d nota(s) de R$ 1,00\n", um);
    return 0;
}
