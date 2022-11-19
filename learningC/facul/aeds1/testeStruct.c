#include <stdio.h>

struct ponto {
    float x;
    float y;
};


void imprime(struct ponto *pp){
    printf("Ponto: (%.1f, %.1f)\n", pp->x, pp->y);
}

void captura(struct ponto *pp){
    printf("Digite as coordenadas do ponto: \n");
    scanf("%f %f", &pp->x, &pp->y);
}

int main(){

    struct ponto *pp;
    pp = (struct ponto*) malloc(sizeof(struct ponto));
    captura(pp);

    printf("The x value is: %.1f\n", pp->x);
    printf("The y value is: %.1f\n", pp->y);
    printf("The x address is: %p\n", &pp->x);
    printf("The y address is: %p\n", &pp->y);

    imprime(pp);
    free(pp);
    return 0;
}