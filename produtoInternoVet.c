#include <stdio.h>

void produtoInterno(int *a, int *b, int *c, int tamanho){
	for(int i=0; i<tamanho; ++i)
	c[i]= a[i] * b[i];
}

int main(){
	int x[3]= {1,2,3}, y[3] = {4,5,6}, z[3];
	produtoInterno(x,y,z,3);

	printf("%d %d %d\n", z[0], z[1], z[2]);
	
	return 0;
}
