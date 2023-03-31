#include <stdio.h>

int main(){
    int x;
    double qtd;
    char tipo;
    double coelho = 0 , rato = 0, sapo = 0, total = 0;
    scanf("%d", &x);
    for(x; x > 0; x--){
        scanf("%lf %c", &qtd, &tipo);
        total += qtd;
        if(tipo == 'C')
            coelho+= qtd;
        else if(tipo == 'S')
            sapo += qtd;
        else
            rato += qtd;
    }
    printf("Total: %lf cobaias\n", total);
    printf("Total de coelhos: %lf\n", coelho);
    printf("Total de ratos: %lf\n", rato);
    printf("Total de sapos: %lf\n", sapo);


    double totalcoelho;
    totalcoelho = (100 * coelho)/total;
    double totalratos = (100 * rato)/total;
    double totalsapo = (100 * sapo)/total;
    printf("Percentual de coelhos: %.2lf \%\n", totalcoelho);
    printf("Percentual de ratos: %.2lf \% \n", totalratos);
    printf("Percentual de sapos: %.2lf \%\n", totalsapo);
    return 0;
}