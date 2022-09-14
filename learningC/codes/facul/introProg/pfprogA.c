/*
RESOLVIDO 1. É possível que vários alunos recebam medalhas do mesmo tipo
RESOLVIDO 2. Pelo menos 1 medalha de cada tipo deve ser entregue
RESOLVIDO 3. O número de medalhistas de ouro tem que ser menor que o número de medalhistas de prata, assim como de bronze: Ouro < Prata e Ouro < Bronze.
RESOLVIDO 4. Cada medalhista de ouro deve ter resolvido mais problemas que outros medalhistas ou aqueles que não recebam medalhas
RESOLVIDO 5. Cada medalhista de prata deve ter resolvido mais problemas que medalhistas de bronze ou aqueles que não recebam medalhas
RESOLVIDO 6. Cada medalhista de bronze deve ter resolvido mais problemas que aqueles que não recebam medalhas
RESOLVIDO 7. O total de medalhistas deve ser menor ou igual à metade do total de alunos
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, k, casosTotais, totalAlunos, *problemasResolvidos, **resultados, metadinha;
    scanf("%d", &casosTotais);
    resultados = (int**) malloc (casosTotais * sizeof(int*));
    for(i = 0; i < casosTotais; i++){
        scanf("%d", &totalAlunos);
        problemasResolvidos = (int*) malloc (totalAlunos * sizeof(int));
        resultados[i] = (int*) malloc (3 * sizeof(int));
        resultados[i] [0] = 0;
        resultados[i] [1] = 0;
        resultados[i] [2] = 0;
        for(j = 0; j < totalAlunos; j++){
            scanf("%d", &problemasResolvidos[j]);
        }
        metadinha = totalAlunos/2 - 1;
        if(problemasResolvidos[metadinha] == problemasResolvidos[0]){
            continue;
        }
        if(problemasResolvidos[metadinha + 1] == problemasResolvidos[metadinha]){
            while(problemasResolvidos[metadinha] == problemasResolvidos[totalAlunos/2]){
                metadinha--;
            }
        }
        resultados[i][0]++;
        j = 1;
        while(problemasResolvidos[j] == problemasResolvidos[j-1]){
            resultados[i][0]++;
            j++;
        }

        if(problemasResolvidos[j] == problemasResolvidos[metadinha]){
            resultados[i][0] = 0;
            continue;
        }
        resultados[i][1]++;
        j++;
        while(problemasResolvidos[j] == problemasResolvidos[j-1] || resultados[i][0] >= resultados[i][1]){
            resultados[i][1]++;
            j++;
        }

        for(k = j ; k <= metadinha; k++){
            resultados[i][2]++;
        }

        if(resultados[i][0] >= resultados[i][1] || resultados[i][0] >= resultados[i][2]){
            resultados[i] [0] = 0;
            resultados[i] [1] = 0;
            resultados[i] [2] = 0;
        }
        
        free(problemasResolvidos);
    }
    for(i = 0; i < casosTotais; i++){
        printf("%d %d %d\n", resultados[i][0], resultados[i][1], resultados[i][2]);
    }
    free(resultados);
    return 0;
}