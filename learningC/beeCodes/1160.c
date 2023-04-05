#include <stdio.h>

int main(){
    int qtd, pa, pb, anos;
    double ca, cb;
    scanf("%d", &qtd);
    for(int i = 0; i < qtd; i++){
        anos = 0;
        scanf("%d %d %lf %lf", &pa, &pb, &ca, &cb);
        while(pa <= pb){
            pa += (pa/100)*ca;
            printf("população resultante A: %d\n", pa);
            pb += (pb/100)*cb;
            anos++;
            if(anos > 100){
                break;
            }
        }
        if(anos > 100)
            puts("Mais de 1 século.");
        else
            printf("%d anos.\n", anos);
    }

    return 0;
}