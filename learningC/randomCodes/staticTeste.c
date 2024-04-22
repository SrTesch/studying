#include <stdio.h>

void myFunction(){
	static int contador = 0;
	contador++;
	printf("%d\n", contador);
}


int soma(int a, int b);

int main(){
	int teste = 10;
	soma = soma(&teste);
	printf("esse é o valor de teste %d\n", teste); 
	myFunction();
	myFunction();
	return 0;
}

soma(int * a){
	a = 20;
}
