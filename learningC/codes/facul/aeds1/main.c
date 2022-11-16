#include <stdio.h>

struct ponto {
        float x;
        float y;
};


void imprime(struct ponto pp){
    printf("Ponto: (%.2f, %.2f)\n", pp.x, pp.y);
}


int main(){

    struct ponto pp;
    pp.x = 10.0;
    pp.y = 5.0;

    printf("The x value is: %.1f\n", pp.x);
    printf("The y value is: %.1f\n", pp.y);
    printf("The x address is: %p\n", &pp.x);
    printf("The y value is: %p\n", &pp.y);

    imprime(pp);

    return 0;
}