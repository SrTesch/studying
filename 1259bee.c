/*
Exercício 1259 do beecrowd(pares e ímpares)
https://www.beecrowd.com.br/judge/pt/problems/view/1259
*/
#include <stdio.h>
#include <stdlib.h>

int valoresPares(const void *x, const void *y){
	int a = *((const int *) x), b = *((const int *) y);
	if(a < b)
		return -1;
	if (a > b)
		return 1;
	return 0;
}

int valoresImpares(const void *x, const void *y){
	int a = *((const int *) x), b = *((const int *) y);
	if(a > b)
		return -1;
	if(a < b)
		return 1;
	return 0;
}

int main(){
	int a, b, vp[1000], vi[1000],contPar=0, contImpar = 0;
	
	scanf("%d", &a);
	for(int i=0; i<a; ++i){
		scanf("%d", &b);
		if(b%2 == 0){
			vp[contPar]= b;
			contPar= contPar + 1;
		}
		else{
			vi[contImpar] = b;
			contImpar= contImpar + 1;
		}
	}
	

	//ordenando os vetores
	qsort(vp, contPar, 4, valoresPares);
	qsort(vi, contImpar, 4, valoresImpares);
	
	//printando os valores
	for(int i=0; i < contPar; ++i){
		printf("%d\n", vp[i]);
	} 
	
	for(int i = 0; i <contImpar; ++i){
		printf("%d\n", vi[i]);
	}
	return 0;
}

