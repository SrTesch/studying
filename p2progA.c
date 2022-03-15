/*

Descrição
Você foi contratado por uma empresa de mídias sociais para analisar uma certa rede social,
na qual cada usuário pode fazer parte de comunidades. A empresa deseja saber o quão
influente são usuários dessa rede, considerando a propagação de informação a partir de cada
um deles. Considere que toda vez que alguém recebe uma informação, a divulga em todos as
comunidades as quais pertence, e toda informação que chega a uma comunidade é recebida
por todos seus membros.

Dadas as listas de usuários em cada comunidade, determine quantos usuários seriam alcançados
por uma informação caso ela tivesse sido recebida inicialmente por cada usuário da rede.

Restrições
O número de usuários (n) e de comunidades (m) são no mínimo 1 e no máximo 5*10^5.
O número de usuários numa comunidade (k) é no mínimo 0 e no máximo n.
Os identificadores dos usuários são números inteiros entre 1 e n.
Entrada
A primeira linha da entrada é:

n m

As m linhas seguintes apresentam uma comunidade, como uma lista de inteiros: o primeiro
inteiro da linha (k) é o número de usuários que pertencem a comunidade; após este, seguem k 
inteiros, que são os identificadores dos usuários que compõem aquela comunidade.

Saída
Apresente numa única linha n valores inteiros separados por espaços, tal que o i-ésimo valor
seja correspondente a quantos usuários seriam alcançados por uma informação inicialmente
divulgada pelo usuário i.

Exemplo 1: entrada
7 5
3 2 5 4
0
2 1 2
1 1
2 6 7

Exemplo 1: saída
4 4 1 4 4 2 2

*/

#include <stdio.h>
int main(){
	int n, m;	
return 0;
}
