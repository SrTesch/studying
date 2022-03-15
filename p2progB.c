/*
Descrição:
Considere a seguinte operação: dada uma string s de n caracteres, escolher um valor k entre 0 e n inclusive, e então permutar (ou seja, trocar de lugar) k caracteres da string.

Por exemplo, se s="cefet", seria possível escolher k=3, e então permutar os caracteres "c_fe_" resultando na string "feect".

Determine o menor k tal que seja possível ordenar s alfabeticamente realizando a operação uma única vez.

Restrições:
s é composta de letras minúsculas simples (sem acentos etc)
n é no mínimo 1 e no máximo 40
Entrada
A entrada é composta de vários casos de teste. A primeira linha contém o número deles. Após ela, os casos de teste são apresentados um após o outro. Cada caso de teste tem o seguinte formato:

n
s

Saída:
Para cada caso de teste, na ordem que foram apresentados, deve ser mostrado o valor de k pedido numa linha.

Exemplo 1: entrada
4
4
dcba
10
codeforces
3
lol
5
aaaaa

Exemplo 1: saída
4
6
2
0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
nesta questão eu pensei o seguinte: vou alocar a mesma string em dois lugares diferentes, ordenar uma delas e depois comparar caracter por caracter. se tiver algum que esteja igual, vou adicionar ao contador para então diminuir no tamanho total da string. O contador vai servir no fim das contas pra mostrar e separar as letras que nao precisaram ser trocadas na operação
*/

int crescente(const void *x, const void *y){	
	char a = *((const char*) x), b = *((const char*) y);
	if (a<b)
		return -1;
	if (a>b)
		return 1;
	
	return 0;
}

int main(){
    int n, leng; 
    char *s, *palavraOrdenada;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &leng);
        int cont = 0;
        s = (char*) malloc ((leng+1)*sizeof(char));
        palavraOrdenada = (char*) malloc (leng*sizeof(char));
        scanf("%s", s);
        strcpy(palavraOrdenada, s); //aqui eu copiei a string
        qsort(palavraOrdenada, leng, sizeof(char), crescente);
        for(int j = 0; j < leng; j++){
            if (s[j] == palavraOrdenada[j]){
                ++cont;
            }
        }
        leng -=cont;
        printf("%d\n", leng);
        free(s); free(palavraOrdenada);
    }

    return 0;
}