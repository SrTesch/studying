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

10 4
3 2 5 4
3 8 9 10
2 10 2
5 1 3 6 7 8
*/



#include <stdio.h>
#include <stdlib.h>

void verificaAlcance(int totalComunidades,int **comunidade, int totalUsuarios,int *verif, int *totalSoma, int i){
	int j, k;
	if(verif[i] == 1 && totalSoma[i] != 0){
		return; 
	}
	//verif[i] = 1;
	for(j = 0; j < totalComunidades; j++){
		if(comunidade[j][i] == 1){
			for(k = 0; k < totalUsuarios; k++){
				if(comunidade[j][k] == 1){
					if(totalSoma[k] != 0){
						totalSoma[i] = totalSoma[k];
						return;
					}
					if(k!= i && verif[k] != 1){
						verificaAlcance(totalComunidades, comunidade, totalUsuarios, verif, totalSoma, k);
					}
					verif[k] = 1;
				}
			}
		}
	}
}

int atualizaAlcance(int totalComunidades,int **comunidade, int totalUsuarios, int *totalSoma, int i){
	int k, j, maior, aux;
	for(j = 0; j < totalComunidades; j++){
		if(comunidade[j][i] == 1){
			for(k = 0; k < totalUsuarios; k++){
				if( comunidade[j][k] == 1){
						aux = atualizaAlcance(totalComunidades, comunidade, totalUsuarios, totalSoma, k);
						maior = (totalSoma[k] > aux)? totalSoma[k] : aux;
					if(maior > totalSoma[i]){
						printf("%d %d %d", i, aux, totalSoma);
						totalSoma[k] = maior;
					}
				}
			}
		}
	}
	return maior;
}

int main(){
	int totalUsuarios, totalComunidades, usuarios, **comunidade, i, j, k, soma, *totalSoma;
	scanf("%d %d", &totalUsuarios, &totalComunidades);
	int *verif;
	verif = malloc(totalUsuarios * sizeof(int));
	totalSoma = malloc(totalUsuarios * sizeof(int));
	comunidade = malloc (totalComunidades * sizeof(int*));
	for(i=0; i < totalComunidades; i++){
		comunidade[i] = malloc(totalUsuarios * sizeof(int));
		scanf("%d", &usuarios);
		for(j = 0; j < totalUsuarios; j++){
			comunidade[i][j] = 0;
		}
		int aux;
		for (j = 0; j < usuarios ; j++){
			scanf("%d", &aux);
			comunidade[i][aux-1] = 1;
		}
	}
	for(i = 0; i < totalUsuarios; i++){
		for(j=0; j < totalUsuarios; j++){
			if(i == 0){
				totalSoma[j] = 0;
			}
			verif[j] = 0;
		}
		verificaAlcance(totalComunidades, comunidade, totalUsuarios, verif,totalSoma, i);
		verif[i] = 1;
		if(totalSoma[i]== 0){
			for(j = 0; j < totalUsuarios; j++){
				totalSoma[i] += verif[j];
			}
		}
		atualizaAlcance(totalComunidades, comunidade, totalUsuarios, totalSoma, i);
		printf("%d ", totalSoma[i]);
	}
return 0;
}
