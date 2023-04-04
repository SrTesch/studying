#include <stdio.h>
 
int main() {
    int x;
    double y, z;
    scanf("%d", &x);
    while(x != 0){
        scanf("%lf %lf", &y, &z);
        if(z == 0){
            puts("divisao impossivel");
            x--;
            continue;
        }else{
            printf("%.1lf\n", y/z);
        }
        x--;
    }
 
    return 0;
}