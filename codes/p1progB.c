/*
Letra B da p1
Descrição:
Dadas duas strings S e T, determine se é possível fazer com
que ambas sejam iguais realizando nelas uma ou mais operações de rotação.
Considere que rotacionar uma string X de tamanho n uma vez é transformá-la
de X=X[1]X[2]…X[n] para X'=X[n]X[1]X[2]…X[n-1].

Restrições
S e T tem o mesmo tamanho, que é no mínimo 1 e no máximo 100
S e T são constituídas de letras minúsculas da língua inglesa
Entrada
A entrada é dada no seguinte formato:
S
T

Saída
A saída deve ser uma única palavra:
"Yes", se for possível equiparar as strings,
ou "No", no caso contrário.

Exemplo 1: entrada
teste
tetes

Exemplo 1: saída
Yes

Exemplo 2: entrada
maria
airam

Exemplo 2: saída
No
*/


#include <stdio.h>

int percorreSegunda(int pos, int step, int tamanho){
    int novaPos = pos + step;
    if(novaPos >= tamanho){
        return novaPos - tamanho;
    }
    return novaPos;
}


int tamanhoDoTexto(char x[101]){
	int cont=0;
	while(x[cont] != '\0')
		cont = cont +1;
	return cont;
}


int main(){
	int z, passo = 0, j;
	char a[101],b[101];
	scanf("%s", a);
	scanf("%s", b);
	
	z = tamanhoDoTexto(a);

	for(int i=0; i<z; ++i){
		j = percorreSegunda(i, passo, z);
		if(a[i]!=b[j]){
			passo = passo + 1;
			i = 0;
		}
		if(passo >= z){
			break;
		}
	}
	if(passo>=z){
		printf("No");
	}else{
		printf("Yes");
	}
	return 0;
}
