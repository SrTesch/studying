#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int operationCount = 0;

void captacaoInicial(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
}

void imprimir(int sudoku[9][9]) {
    puts("-------------------------");
    for (int i = 0; i < 9; i++) {
        printf("| ");
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
            if( (j+1) % 3 == 0)
                printf("| ");
        }
        printf("\n");
        if( (i+1) % 3 == 0)
            puts("-------------------------");
    }
}



bool encontrarPosicaoVazia(int sudoku[9][9], int* linha, int* coluna) {
    for (*linha = 0; *linha < 9; (*linha)++) {
        for (*coluna = 0; *coluna < 9; (*coluna)++) {
            if (sudoku[*linha][*coluna] == 0)
                return true;
        }
    }

    return false;
}

bool podeInserir(int sudoku[9][9], int linha, int coluna, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[linha][i] == num)
            return false;
    }

    for (int i = 0; i < 9; i++) {
        if (sudoku[i][coluna] == num)
            return false;
    }

    int inicioLinha = linha - (linha % 3);
    int inicioColuna = coluna - (coluna % 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[inicioLinha + i][inicioColuna + j] == num)
                return false;
        }
    }

    return true;
}

bool resolver(int sudoku[9][9]) {
    int linha, coluna;

    if (!encontrarPosicaoVazia(sudoku, &linha, &coluna)) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        operationCount++;
        if (podeInserir(sudoku, linha, coluna, num)) {
            sudoku[linha][coluna] = num;

            if (resolver(sudoku))
                return true;
            
            sudoku[linha][coluna] = 0;
        }
    }

    return false;
}

int main() {
    clock_t start, end;
    double executionTime;
    
    start = clock(); // Inicia a contagem do tempo

    int sudoku[9][9];

    captacaoInicial(sudoku);

    if (resolver(sudoku)){
        end = clock(); // Finaliza a contagem do tempo
        executionTime = ((double) (end - start)) / CLOCKS_PER_SEC * 1000; // Tempo de execução em milissegundos
        
        imprimir(sudoku);
        printf("\nNúmero de operações: %d\n", operationCount);
        printf("Tempo de execução: %.2f ms\n", executionTime);
    }else
        printf("Impossível resolver o Sudoku.\n");
    

    return 0;
}