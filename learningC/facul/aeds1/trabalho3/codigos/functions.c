#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/functions.h"
#include <unistd.h>

void enterVoltar() {
    char aux;
    printf("\nPressione ENTER para voltar.");
    scanf("%c", &aux);
    getchar();
}

no ** criarLista(){
    no **fs = malloc(sizeof(no *) * MAX_LIST_LENGHT);

    for(int i = 0; i < MAX_LIST_LENGHT; i++){
        fs[i] = (no *) malloc(sizeof(no)); // cria um novo nó
        strcpy(fs[i]->conteudo, "");
        fs[i]->prox_arq = -1;
    }
    return fs;
}

int inserir(int inicio, char *text, no ** lista){
    int aux = inicio;
    while(lista[aux] != NULL && strcmp(lista[aux]->conteudo, "") != 0){
        aux++;
    }
    strcpy(lista[aux]->conteudo, text);
    lista[inicio]->prox_arq = aux; 
    return aux;
}

int ler_arq(no **lista, int espacos_livres, arquivo ** lista_arq){
    system("clear");
    int inicial = 0, ultimo = 0, inseridos = 0;

    char arq[60];
    printf("Digite o nome do arquivo que deseja inserir:\n");
    scanf("%s", arq);
    int aux = end_arq(lista_arq, arq);
    if(aux != -1){
        printf("\x1b[1;31mOpa!! Parece que este arquivo já foi inserido. Não é possível inserir o mesmo arquivo duas vezes!\n\x1b[1;36m");
        enterVoltar();
        return 0;
    }
    
    FILE *textfile;
    char texto[60];
    textfile = fopen(arq, "r");
    if(textfile == NULL){
        printf("\x1b[1;31mArquivo vazio ou Não encontrado\n\x1b[1;36m");
        enterVoltar();
        return 0;
    }
    int tam_arq = 0;

    while(fgets(texto, 60, textfile))
        tam_arq++;
    
    if(tam_arq > espacos_livres){
        printf("\x1B[1;31mInfelizmente não há mais espaços livres ou o arquivo é muito grande!\nTente apagar algum outro arquivo antes!\n");
        enterVoltar();
        return 0;
    }else{
        fseek(textfile, 0, SEEK_SET);
        fgets(texto, 60, textfile);
        inicial = inserir(ultimo, texto, lista);
        ultimo = inicial;
        while(fgets(texto, 60, textfile)){
            ultimo = inserir(ultimo, texto, lista);
            inseridos++;
        }
    }
    fclose(textfile);

    /* Nesta parte o arquivo está sendo inserido na lista de arquivos com todos os seus metadados! */
    int i = 0;
    while(lista_arq[i] != NULL)
        i++;

    lista_arq[i] = (arquivo *) malloc(sizeof(arquivo)); //criando um novo nó
    strcpy(lista_arq[i]->nome_do_arquivo, arq);
    lista_arq[i]->inicio = inicial;
    lista_arq[i]->num_blocos = tam_arq;

    puts("\x1b[1;33mArquivo Inserido!\x1b[1;36m");
    enterVoltar();
    return inseridos;
}

int end_arq(arquivo ** lista_arq, char * arq){
    int comeco;
    for(int i = 0; i < 100; i++){
        if(lista_arq[i] != NULL && strcmp(lista_arq[i]->nome_do_arquivo, arq) == 0){
            comeco = lista_arq[i]->inicio;
            return comeco;
        }
    }
    return -1;
}

int remover_arq(arquivo ** lista_arq, no **lista){
    system("clear");
    int removidos = 0;
    int comeco, anterior, tamanho_arq;
    char arq[50];
    printf("Digite o nome do arquivo que deseja remover: ");
    scanf("%s", arq);
    
    int aux;
    for(int i = 0; i < 100; i++){
        if(lista_arq[i] != NULL && strcmp(lista_arq[i]->nome_do_arquivo, arq) == 0){
            aux = i;
            break;
        }
    }

    comeco = end_arq(lista_arq, arq);
    if(comeco == -1){
        printf("\x1b[1;31mPoxa! Parece que este arquivo ainda não foi inserido.\n\x1b[1;36m");
        enterVoltar();
        return removidos;
    }
    tamanho_arq = lista_arq[aux]->num_blocos;
    
    for(int j = 0; j < tamanho_arq; j++){
        strcpy(lista[comeco]->conteudo, "");
        anterior = comeco;
        comeco = lista[comeco]->prox_arq;
        lista[anterior]->prox_arq = -1;
        removidos++;
    }

    free(lista_arq[aux]);
    lista_arq[aux] = NULL;
    printf("\x1b[1;33mArquivo Removido!\x1b[1;36m");
    enterVoltar();
    return removidos;
}

void imprimir_arq(arquivo ** lista_arq, no **lista){
    system("clear");
    char arq[50];
    printf("Digite o nome do arquivo que deseja buscar: ");
    scanf("%s", arq);

    int comeco = end_arq(lista_arq, arq);
    if(comeco == -1){
        printf("\x1b[1;31mPoxa! Parece que este arquivo ainda não foi inserido.\n\x1b[1;36m");
        enterVoltar();
        return;
    }
    int tamanho_arq;
    int aux;
    for(int i = 0; i < 100; i++){
        if(lista_arq[i] != NULL && strcmp(lista_arq[i]->nome_do_arquivo, arq) == 0){
            aux = i;
            break;
        }
    }

    tamanho_arq = lista_arq[aux]->num_blocos;
    for(int i = 0; i < tamanho_arq; i++){
        printf("\x1B[1;33mBloco nº%d\n", comeco);
        printf("  Conteúdo=> %s\n", lista[comeco]->conteudo);
        printf("  Endereço de memória=> %p\n", lista[comeco]);
        comeco = lista[comeco]->prox_arq;
    }

    printf("\nOcupa %d Blocos\n\x1b[1;36m", tamanho_arq);
    enterVoltar();
    return;
}

void imprimir_lista(arquivo ** lista_arq, no ** lista){
    for(int i = 0; i < MAX_LIST_LENGHT; i++){
        printf("Nó - %d\n", i+1);
        printf("  Endereço - %p\n", lista[i]);
        printf("  Conteudo - %s\n", lista[i]->conteudo);
    }
    printf("\n\n");
    puts("Arquivos inseridos:");
    puts("Nome do Arquivo - Inicio - Tamanho");

    for(int j = 0; j < 100; j++){
        if(lista_arq[j] == NULL)
            break;
        
        printf("%s - %d - %d\n", lista_arq[j]->nome_do_arquivo, lista_arq[j]->inicio, lista_arq[j]->num_blocos);
        
    }
    enterVoltar();
}

void buscar_termo(arquivo ** lista_arq, no ** lista){
    system("clear");

    char termo[20];
    printf("Digite o termo que deseja procurar: \n");
    scanf("%s", termo);

    int indice = 0;

    if(lista_arq[0] == NULL){
        printf("\x1B[1;31mParece que a lista ainda está vazia!\nInsira algum arquivo antes de procurar algum termo!\x1B[1;36m\n");
        return;
    }

    int arq_atual = 0, atual;
    puts("\x1B[1;33mNome do arquivo - Ocorrências");
    while(lista_arq[arq_atual] != NULL){
        atual = lista_arq[arq_atual]->inicio;
        int tamanho_arq = lista_arq[arq_atual]->num_blocos;
        int contador = 0;
        for(int i = 0; i < tamanho_arq; i++){
            do{
                indice = existe(lista[atual]->conteudo, termo, indice);
                if(indice != -1)
                    contador++;
            }while(indice != -1);
            atual = lista[atual]->prox_arq;
        }
        printf("%s - %d\n", lista_arq[arq_atual]->nome_do_arquivo, contador);
        indice = 0;
        arq_atual++;
    }
    puts("\x1B[1;36m");
    enterVoltar();
}

int existe(char *str1, char *str2, int indice){
    int i, aux = 0;

    for(i = indice; i < strlen(str1); i++){
        if(str1[i] == str2[aux])
            aux++;
        else
            aux = 0;
        if(aux == strlen(str2))
            return i;
    }
    return -1;
}