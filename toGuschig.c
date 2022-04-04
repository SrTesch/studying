#include <stdio.h>

int main(){
	int i, totalPessoas, aux, somaTotal = 0, media;
	scanf("%d", &totalPessoas);
	for(i = 0; i < totalPessoas; i++){
		scanf("%d", &aux);
		somaTotal += aux;
	}
	media = somaTotal / totalPessoas;
	printf("%d", media);
	return 0;
}
