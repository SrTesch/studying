#include <stdio.h>

int main() {
    
    int n;
    char num[5], sym[11];
    
    
    
    
    for(;;){
        
        scanf("%d", &n);
        
        if (n == 0) break;
        
        int cartas[3][3];
        
        //zerando a matriz
        
        for(int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cartas[i][j] = 0;
            }
        }
        
        int sets = 0;
        
        
        
        //Input do vetor
        
        for(int i = 0; i < n; ++i) {
            scanf("\n%[^ ] ", num);
            scanf("%[^\n]\n", sym);
            
            
            //printf("%c\n", num[0]);
            //printf("%c\n\n", sym[0]);
            
            if (num[0] == 'u' && sym[0] == 'c') {
                cartas[0][0] += 1;
            } else if (num[0] == 'u' && sym[0] == 't') {
                cartas[1][0] += 1;
            } else if (num[0] == 'u' && sym[0] == 'q') {
                cartas[2][0] += 1;
            } else if (num[0] == 'd' && sym[0] == 'c') {
                cartas[0][1] += 1;
            } else if (num[0] == 'd' && sym[0] == 't') {
                cartas[1][1] += 1;
            } else if (num[0] == 'd' && sym[0] == 'q') {
                cartas[2][1] += 1;
            } else if (num[0] == 't' && sym[0] == 'c') {
                cartas[0][2] += 1;
            } else if (num[0] == 't' && sym[0] == 't') {
                cartas[1][2] += 1;
            } else {
                cartas[2][2] += 1;
            }
        }
        
        
        // DEBUGG da matriz imput
    
        printf("\n--------------------\n\n");
        
        for(int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                printf("%d ", cartas[i][j]);
            }
        printf("\n");
        }
        
        printf("\n--------------------\n\n");
        
        
        
        /*
        //achando o menor
        
        int menor = cartas[0][0];
        
        for(int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(cartas[i][j] < menor && cartas[i][j] != 0)  menor = cartas[i][j];
            }
        }
        */
        
        
        //formando sets com simbolos e numeros diferentes
        
        for(int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                
                //encontrou o menor
                
                if(cartas[i][j] != 0){
                    
                    //procura sets com numeros e simb diferentes 
                    
                    for(int p = 0; p < 3; ++p){
                        for (int q = 0; q < 3; ++q) {
                          
                            if((p != i && q != j) && cartas[p][q] != 0 && cartas[i][j] != 0){
                              
                                for(int x = 0; x < 3; ++x){
                                    for(int y = 0; y < 3; ++y){
                                      
                                        if((x != i && y != j)&&(x != p && y != q) && cartas[x][y] != 0 && cartas[p][q] != 0 && cartas[i][j] != 0){
                                            sets += 1;
                                            cartas[i][j] -= 1;
                                            cartas[p][q] -= 1;
                                            cartas[x][y] -= 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        
        // sets repetidos
        for(int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(cartas[i][j] >= 3){
                    sets += cartas[i][j]/3;
                    cartas[i][j] -= 3 * (cartas[i][j]/3);
                }
            }
            
        }
        
        // sets em colunas
        for(int i = 0; i < 3; ++i) {
            if(cartas[i][0] != 0 && cartas[i][1] != 0 && cartas[i][2] != 0){
                    sets += 1;
                    cartas[i][0] -= 1;
                    cartas[i][1] -= 1;
                    cartas[i][2] -= 1;
                }
        }
        
        //sets em linhas
        for(int i = 0; i < 3; ++i) {
            if(cartas[0][i] != 0 && cartas[1][i] != 0 && cartas[2][i] != 0){
                    sets += 1;
                    cartas[0][i] -= 1;
                    cartas[1][i] -= 1;
                    cartas[2][i] -= 1;
                }
        }
        
    // DEBUGG resultado
    
    printf("%d\n", sets);
    
    
    // DEBUGG da matriz resultado
    
    printf("\n--------------------\n\n");
    
    for(int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", cartas[i][j]);
        }
    printf("\n");
    }
    
    printf("\n--------------------\n\n");
    
    
    }
    return 0;
}