#include <stdio.h>

int main(){
    int i, m, n, x = 1, aux, total;
    while (x = 1){
        total = 0;
        scanf("%d %d", &m, &n);
        if (m <= 0 || n <= 0){
            break;
        }
        if(m < n){
            aux = m;
            m = n;
            n = aux;
        }
        for(i = n; i <= m; i++){
            total += i;
            printf("%d ", i);
        }
    printf("Sum=%d\n", total);
    }
    return 0;
}