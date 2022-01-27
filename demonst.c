#include <stdio.h>

int main(){
	int a, aux;
	double ger = 0;
	puts("Este é um programa que calcula a média de idade das pessoas\n");
	puts("Digite quantas pessoas você quer calcular\n");
	scanf("%d", &a);
	for(int i =0; i<a; ++i){
		scanf("%d", &aux);
		ger= ger+aux;
	}
	ger = ger/a;
	printf("Esta é a média de idade: %.1lf\n", ger);

	return 0;
}
