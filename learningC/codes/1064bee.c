#include <stdio.h>

int main(){
    double i, scan, sum = 0, media;
    int cont = 0;
    for(i = 0; i < 6; i++){
        scanf("%lf", &scan);
        if(scan > 0){
            cont += 1;
            sum += scan;
        }
    }
    printf("%d valores positivos\n", cont);
    media = sum/cont;
    printf("%.1lf\n", media);
    return 0;
}