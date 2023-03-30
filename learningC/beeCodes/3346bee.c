#include <stdio.h>

int main(){
    double x, y;
    scanf("%lf %lf", &x, &y);
    double res = 100;
    res *= 1 + x/100;
    res *= 1 + y/100;
    res -= 100;
    printf("%.6lf\n", res);
    return 0;
}