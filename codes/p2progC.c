/*
Descrição
No Xadrez, o rei e a rainha são duas peças que, de certa forma, podem se mover de forma semelhante: ambos podem ir na direção de qualquer uma das até 8 casas vizinhas à posição onde se encontram inicialmente. Há porém uma diferença: num movimento o rei só pode dar um único "passo" em qualquer uma dessas direções, enquanto a rainha pode dar quantos passos quiser.

Dada a posição do rei e a posição da rainha num tabuleiro no qual eles são as únicas peças presentes, determine se é possível que o rei se movimente até uma certa posição do tabuleiro sem passar por qualquer casa que poderia ser alcançada pela rainha num único movimento.

Restrições
Considere que o jogo é realizado num tabuleiro de n linhas e n colunas, com n entre 3 e 1000 inclusive
As coordenadas das posições do rei (Ki Kj), da rainha (Qi Qj) e de destino (Di Dj) são valores entre 1 e n inclusive.
Entrada
A entrada é dada no seguinte formato:

n
Qi Qj
Ki Kj
Di Dj

Saída
Na saída, mostre "YES" caso seja possível que o rei realize a ação descrita, e "NO" caso contrário.

Exemplo 1: entrada
8
4 4
1 3
3 1

Exemplo 1: saída
YES

Exemplo 2: entrada
8
3 5
1 2
6 1

Exemplo 2: saída
NO
*/

#include <stdio.h>

int main(){
    int n, Qi, Qj, Ki, Kj, Di, Dj;
    scanf("%d", &n);
    scanf("%d %d", &Qi, &Qj);
    scanf("%d %d", &Ki, &Kj);
    scanf("%d %d", &Di, &Dj);
    if (Ki > Qi && Di > Qi || Ki < Qi && Di < Qi){ //definindo se estão na mesma posição/quadrante referente às COLUNAS da Rainha
        if (Kj > Qj && Dj > Qj || Kj < Qj && Dj < Qj){ //definindo se estão na mesma posição/quadrante referente às COLUNAS da Rainha
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }else{
        printf("NO\n");
    }
    
    return 0;
}