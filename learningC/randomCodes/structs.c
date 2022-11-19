#include <stdio.h>

int main(void){
    float notas[20]; //vetor com 20 notas diferentes
    float mnotas[10][2]; //matriz com 10 linhas e 2 colunas

    struct fichaAluno{ //apenas um tipo de dado. nao tem valor ainda
    int numero;
    float nota;
    char nome[40];    
    }; //definição do struct
    
    struct fichaAluno aluno;//declaração da variável aluno que é do tipo struct

    printf("\n---------Cadastro de Aluno---------\n\n\n");
    printf("Nome do aluno......:");
    fgets(aluno.nome,40,stdin);
    
    printf("Digite o número do aluno: ");
    scanf("%d", &aluno.numero);

    printf("Informe a nota do aluno: ");
    scanf("%f", &aluno.nota);

    printf("\n\n ---------Lendo os dados da struct---------\n\n");
    printf("Nome........: %s", aluno.nome);
    printf("Número......: %d\n", aluno.numero);
    printf("Nota........: %.2f\n", aluno.nota);

    return 0;
}