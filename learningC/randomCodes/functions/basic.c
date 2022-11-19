#include <stdio.h>

int areaDoRet(int larg, int alt){
    int area;
    area = larg * alt;
    return area;
}

int main(){
    int l, a;
    printf("Digite a altura do seu retângulo:\n");
    scanf("%d", &a);
    printf("Digite a largura do seu retângulo:\n");
    scanf("%d", &l);
    int area = areaDoRet(l,a);
    printf("A área do seu retângulo é %d\n", area);
    return 0;
}