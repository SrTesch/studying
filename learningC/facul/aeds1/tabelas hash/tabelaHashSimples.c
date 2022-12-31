//nao tem tratamento de colisão

#include <stdio.h> 

void imprimirTabela(int *tabela){
    for(int i = 0; i < 10; i++){
        printf("%d => %d\n", i, tabela[i]);
    }
}

int main(){
    puts("Bem vindo à central da Tabela Hash (1º exemplo)!!");
    int tabela[10];
    for(int i = 0; i < 10; i++){
        tabela[i] = -1;
    }
    int aux =1, pos, toModify;
    while(aux != 0){
        printf("\nOpções:\n(1) Inserir um elemento\n(2) Apagar um elemento\n(3) Imprimir toda a Tabela\n(0) Sair\n");
        scanf("%d", &aux);
        if(aux == 1){
            system("clear");
            printf("Digite o numero que deseja inserir na tabela: ");
            scanf("%d", &toModify);
            pos = toModify %10;
        
            if(tabela[pos] != -1)
                printf("Já existe o valor %d inserido nesta posição!", tabela[pos]);
            else{
                tabela[pos] = toModify;
                puts("Elemento inserido");
            }
        }else if(aux == 2){  //função de apagar um elemento
            system("clear");
            printf("Digite o elemento que deseja remover: ");
            scanf("%d", &toModify);
            pos = toModify %10;
            
            if(tabela[pos] == toModify){
                tabela[pos] = -1;
                puts("Elemento removido");
            }
            else
                puts("Parece que este valor não foi inserido ainda!");


        }else if(aux == 3){
            system("clear");
            imprimirTabela(&tabela);
        }
    }
}