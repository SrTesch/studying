#include <stdio.h>
#include <stdlib.h>

int criterioOrdenacaoCrescente(const void *x, const void *y){	
	int a = *((const int*) x), b = *((const int *) y);
	if (a<b)
		return -1;
	if (a>b)
		return 1;
	
	return 0;
}

int ordemDecrescente(const void *x, const void *y){
	int a= *((const int*)x), b = *((const int *)y);
	if (a>b)
		return -1;
	if (a<b)
		return 1;
	return 0;
}

int main(){
	int a[] = {1,3,5,7,9,0,8,6,4,2};
	
	qsort(a, 10, 4, criterioOrdenacaoCrescente);
	
	for(int i=0; i<10; ++i){
		printf("%d: %d\n", i, a[i]);
	}
	
	puts("---------");
	
	qsort(a, 10, 4, ordemDecrescente);
	
	for(int i =0; i<10; ++i){
		printf("%d: %d\n", i, a[i]);
	}
	
	return 0;
}
