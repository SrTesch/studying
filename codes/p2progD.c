/*
Descrição
Você foi contratado por um dono de uma empresa multinacional para trabalhar num projeto de uma fazenda high-tech, que produzirá alimentos com muito mais eficiência que uma fazenda normal. Sua primeira tarefa é desenvolver um sistema de análise de imagens de satélite para proteger vacas geneticamente modificadas de lobos predadores enquanto elas pastam. Tal análise deverá indicar locais específicos do pasto nos quais cães-pastores robóticos deverão ser posicionados para que os lobos não consigam chegar até as ovelhas.

Considere o pasto como uma grade de N linhas e M colunas em que cada posição está inicialmente vazia (.), com uma ovelha (S, sheep), ou um lobo (W, wolf). Inicialmente não há cães-pastores no pasto, mas eles serão identificados pela letra D (dog). Para chegar até uma ovelha um lobo pode ir para cima, baixo, esquerda ou direita. Já as ovelhas e cães são considerados imóveis.

Dada a descrição de um pasto, apresente como ele ficará com uma quantidade qualquer de cães-pastores posicionados de forma que nenhum lobo possa alcançar qualquer ovelha, ou indique que é impossível garantir a segurança das ovelhas. Qualquer forma de garantir a segurança das ovelhas é igualmente válida.
Restrições
- N e M valem no mínimo 1 e no máximo 500
Entrada
A entrada é dada no seguinte formato:
N M
P[1,1] P[1,2] ... P[1, M]
P[2,1] P[2,2] ... P[2, M]
...
P[N,1] P[N,2] ... P[N, M]

P[i,j] é uma das posições do pasto, que pode estar inicialmente vazia, com uma ovelha, ou com um lobo.
Saída
Caso seja impossível garantir a segurança das ovelhas, mostre apenas "No".
Senão, mostre "Yes" e a paritr da linha de baixo mostre a configuração do pasto já com os cães-pastores robóticos posicionados.
Exemplo 1: entrada
6 6
..S...
..S.W.
.S....
..W...
...W..
......
Exemplo 1: saída
Yes
..SD..
..SDW.
.SD...
.DW...
DD.W..
......
Exemplo 2: entrada
1 2
SW
Exemplo 2: saída
No
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int linhas, colunas, i, j, ganhou = 1;
    char **pasto;
    scanf("%d %d", &linhas, &colunas);
    pasto = malloc  (linhas * sizeof(char*));
    for(i=0; i < linhas; i++){
        pasto[i] = malloc ((colunas+1) * sizeof(char));
        scanf("%s", pasto[i]);
    }

    for(i=0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            if(pasto[i][j] == 'S'){
                if(i>0){
                    if(pasto[i-1][j] == '.'){
                        pasto[i-1][j] = 'D';
                    }else if(pasto[i-1][j] == 'W'){
                        ganhou = 0;
                        break;
                    }
                }
                if(i<linhas-1){
                    if(pasto[i+1][j] == '.'){
                        pasto[i+1][j] = 'D';
                    }else if(pasto[i+1][j] == 'W'){
                        ganhou = 0;
                        break;
                    }
                }
                if(j>0){
                    if(pasto[i][j-1] == '.'){
                        pasto[i][j-1] = 'D';
                    }else if(pasto[i][j-1] == 'W'){
                        ganhou = 0;
                        break;
                    }
                }
                if(j<colunas-1){
                    if(pasto[i][j+1] == '.'){
                        pasto[i][j+1] = 'D';
                    }else if(pasto[i][j+1] == 'W'){
                        ganhou = 0;
                        break;
                    }
                }
            }
        }
        if(!ganhou){
            break;
        }
        
    }
    if(ganhou){
        printf("Yes\n");
        for(i = 0; i < linhas; i++){
            printf("%s\n", pasto[i]);
        }
    }else{
        puts("No");
    }
    return 0;
}