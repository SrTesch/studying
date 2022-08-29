#include <stdio.h>
#include <string.h>

int main(){
    printf("Bem vindo ao SurferLife\nA qualquer momento do programa... quando quiser sair, digite '0'\n");
    char estado_atual [16]= "Sentado", entrada[] = "1";
    
    while(entrada != "0"){
        printf("O estado atual é: %s\n", estado_atual);
        
        if(strcmp(estado_atual,"Sentado") == 0){
            printf("Digite '1' para vir uma onda\n");
            scanf("%s", entrada);
            if(entrada[0] == '1'){
                strcpy(estado_atual,"Remando");
            }else if(entrada[0] == '0'){
                break;
            }else{
                printf("Entrada inválida\n");
            }
        }else if(strcmp(estado_atual,"Remando") == 0){
            printf("Digite '1' para Conseguir pegar uma onda\nDigite '2' para não conseguir e remar de volta ao estado Sentado\n");
            scanf("%s", entrada);
            if(entrada[0] == '1'){
                strcpy(estado_atual,"Surfando");
            }else if(entrada[0] == '2'){
                strcpy(estado_atual,"Sentado");
            }else if(entrada[0] == '0'){
                break;
            }else{
                printf("Entrada inválida\n");
            }
        }else if(strcmp(estado_atual,"Surfando") == 0){
            printf("Digite '1' para Surfar até o fim da onda\nDigite '2' para tomar um caldo\n");
            scanf("%s", entrada);
            if(entrada[0] == '1'){
                printf("Você conseguiu surfar até o fim da onda\nRemando até o estado Sentado\n");
                strcpy(estado_atual,"Sentado");
            }else if(entrada[0] == '2'){
                printf("Você tomou um caldo\n");
                strcpy(estado_atual,"Descansando");
            }else if(entrada[0] == '0'){
                break;
            }else{
                printf("Entrada inválida\n");
            }
        }else if(strcmp(estado_atual,"Descansando") == 0){
            printf("Digite '1' para voltar ao estado Sentado\n Digite '2' para descansar mais\n");
            scanf("%s", entrada);
            if(entrada[0] == '1'){
                printf("Remando para o estado Sentado\n");
                strcpy(estado_atual,"Sentado");
            }else if(entrada[0] == '2'){
                printf("Descansando mais\n");
                strcpy(estado_atual,"Descansando");
            }else if(entrada[0] == '0'){
                break;
            }
        }
    }
    return 0;
}