/*
Descrição:
Considere o seguinte jogo: 
dado um vetor A de N números (A[1], A[2], …, A[N]), a cada rodada você
deve ou multiplicar por 3 ou dividir por 2 cada um dos números, não sendo
permitido somente multiplicar numa rodada nem gerar números não-inteiros.
Qual o número máximo de rodadas do jogo?

Restrições:
N é um inteiro que vale no mínimo 1 e no máximo 10^4
Cada A[i] é um inteiro que vale no mínimo 1 no máximo 10^9
Entrada
A entrada é dada no seguinte formato:

N
A[1] A[2] … A[N]

Saída:
Na saída deve ser apresentado um único valor: o número máximo de rodadas
do jogo.

Exemplo 1: entrada
3
5 2 4

Exemplo 1: saída
3
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int  n,i, allImpar = 1;  
    scanf("%d", &n);

    int a[n], cont = 0;
    for(i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++){
       if(a[i] % 2 == 0){
          allImpar = 0; 
      }
    }
  
    //loop da rodada
    while(!allImpar){

      //loop calculos
      for(int j = 0; j < n; ++j){
          if(a[j]%2 == 0){
              a[j] = a[j]/2;
              break;
          }
      }

      //loop verificacoes
      allImpar = 1;
      for(i = 0; i < n; i++){
        if(a[i] % 2 == 0){
          allImpar = 0; 
          break;
        }
      }

      cont = cont+1;
    }
	printf("%d", cont);
    return 0;
}
