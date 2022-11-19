#include <stdio.h>

int main(){ //neste código resolvi usar uma variavel auxiliar para poder eliminar as partes que eu nao queria no input, aproveitando pra ja trazer como inteiro os numeros...
    char aux;
    int diaIni, diaFim, horaIni, minIni, segIni, horaFim, minFim, segFim;
    scanf("%s %d", &aux, &diaIni);
    scanf("%d %s %d %s %d", &horaIni, &aux, &minIni, &aux, &segIni);
    scanf("%s %d", &aux, &diaFim);
    scanf("%d %s %d %s %d", &horaFim, &aux, &minFim, &aux, &segFim);


    int diasTotais = diaFim - diaIni, horasTotais, minsTotais, segsTotais;
    if(segFim < segIni){
        segsTotais = 60 - (segFim - segIni);
    }else{
        segsTotais = segFim - segIni;
    }
    return 0;
}