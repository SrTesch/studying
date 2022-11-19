#include <stdio.h>
#include <string.h>
#include <iostream>
int main(){
  int N = 1, figCir = 1, figQua = 1, figTri = 1, num1 = 1, num2 = 1, num3 = 1;
  char numero[5], formato[11];
  char um[] = {"um"}, dois[] = {"dois"}, tres[] = {"tres"};
  char circulo[] = {"circulo"}, quadrado[] = {"quadrado"}, triangulo[] = {"triangulo"};
  while(N){
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
      scanf("%s %s", &numero, &formato);
      if (formato[0] == circulo[0]){
          figCir++;
      }
      else if (formato[0] == quadrado[0]){
          figQua++;
      }
      else{
          figTri++;
      }

      if(numero[0] == um[0]){
          num1++;
      }
      else if(numero[0] == dois[0]){
          num2++;
      }
      else{
          num3++;
      }
    }
    if (N == 0) {
      printf("Encerrou\n");
      return 0;
    }
  }
}