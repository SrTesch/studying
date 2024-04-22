#include <stdio.h>
#include <stdlib.h>
int main() {
    char n[10];
    double sf, tv, k, u;
    scanf("%s lf %lf",n, &sf, &tv);
    k = 15/100 * tv;
    u = sf + k;
    printf("TOTAL = R$ %.2lf\n", u);
    return 0;
}
