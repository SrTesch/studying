/*
Exercício 1259 do beecrowd(pares e ímpares)
https://www.beecrowd.com.br/judge/pt/problems/view/1259
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b, vp[1000], vi[1000], vf[1000];
	
	scanf("%d", &a);
	for(int i=0; i<a; ++i){
		scanf("%d", &b);
		if(b%2 == 0)
			vp[i]= b;
		vi[i] = b;
	}
	
	return 0;
}
