/*
Letra C da p1

Descrição:
Você foi contratado pela prefeitura da sua cidade para
minimizar o custo de decorar árvores no próximo natal.
O custo da decoração é determinado pela diferença de altura
entre a menor e a maior árvore a serem decoradas.
Dadas as alturas h[i] de N árvores, qual o menor custo para
que K delas sejam decoradas?

Restrições:
N vale no mínimo 2 e no máximo 10^5
K vale no mínimo 2 e no máximo N
Cada h[i] vale no mínimo 1 e no máximo 10^9
Cada h[i] é um valor inteiro
Entrada
A entrada é dada no seguinte formato:
N K
h[1]
h[2]
.
.
.
h[N]

Saída
Na saída deve ser exibido um único valor inteiro:
o menor custo para que K das N árvores sejam decoradas.

Exemplo 1: entrada
5 3
10
15
11
14
12

Exemplo 1: saída
2

Exemplo 2: entrada
5 3
5
7
5
7
7

Exemplo 2: saída
0
*/

#include <stdio.h>
#include <stdlib.h>

int crescente(const void *x, const void *y){	
	int a = *((const int*) x), b = *((const int *) y);
	if (a<b)
		return -1;
	if (a>b)
		return 1;
	
	return 0;
}

int grupo(int tamanho, int elementos, int a[100001]){
    int i = 0, menor = a[elementos-1], diferenca;
    while(i+elementos - 1 < tamanho){
        int posFinal = i +elementos - 1;
        diferenca =a[posFinal] - a[i];
        if(diferenca < menor)
            menor = diferenca;
        ++i;
    }
    return menor;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int h[n];
    for(int i = 0; i<n; ++i)
        scanf("%d", &h[i]);
    qsort(h, n, sizeof(int), crescente);

    printf("%d", grupo(n, k, h));

    return 0;
}
