#include <stdio.h>

int main(){
    int a, b, total, n, i;
    printf("Digite o número de termos:\n");
    scanf("%d", &n);

    a = 0;
    b = 1;

    for(i = 0; i < n; i++){
        printf("%d ", b);
        total = a + b;
        a = b;
        b = total;
    }
    printf("\n");
    return 0;
}