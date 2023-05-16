#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ARVORE.C qwRFWÇOEIUJGFTHÇAWOEISHDGFOWIQEHDGFWÇALEOKDJHFG

typedef struct __list{
    char palavra[20];
    struct __list * prox;
    struct __list * ant;
}list;

typedef struct __noAVL{
    char letra; //indice que vai servir para indexação (?) da arvore
    int fb; //fator de balanceamento
    list * inicio;
    struct __noAVL * pai;
    struct __noAVL * esq;
    struct __noAVL * dir;
}noAVL;

int searchInList(list ** lista, char p[20]){
    list * atual = (*lista);

    if(strcmp(atual->palavra, p) == 0)
        return 1;
    
    while(atual != NULL){
        if(strcmp(atual->palavra, p) == 0)
            return 1;
        if(atual->prox != NULL)
            atual = atual->prox;
        else
            break;
    }

    return 0;
}

noAVL * newTree(char inicial){
    noAVL * new = (noAVL *) malloc(sizeof(noAVL));
    new->fb = 0;
    new->letra = inicial;
    new->pai = NULL;
    new->dir = NULL;
    new->esq = NULL;
    new->inicio = NULL;
    return new;
}

noAVL * newNode(noAVL ** pai, char inicial){
    noAVL * new = (noAVL *) malloc(sizeof(noAVL));
    new->fb = 0;
    new->letra = inicial;
    new->pai = (*pai);
    new->inicio = NULL;
    return new;
}

void RR(noAVL ** pai){

    noAVL * aux = (*pai)->esq;
    
    
    if((*pai)->pai != NULL)
        aux->pai = (*pai)->pai;
    else
        aux->pai = NULL;


    if(aux->dir != NULL){
        (*pai)->esq = aux->dir;
        (*pai)->esq->pai = (*pai);
    }else
        (*pai)->esq = NULL;


    aux->dir = (*pai);
    
    (*pai)->pai = aux;
}

void LL(noAVL ** pai){

    noAVL * aux = (*pai)->dir;
    
    
    if((*pai)->pai != NULL)
        aux->pai = (*pai)->pai;
    else
        aux->pai = NULL;


    if(aux->esq != NULL){
        (*pai)->dir = aux->esq;
        (*pai)->dir->pai = (*pai);
    }else
        (*pai)->dir = NULL;


    aux->esq = (*pai);
    
    (*pai)->pai = aux;
}

void balanceAVL(noAVL ** node) {
    if (node == NULL) {
        return;
    }

    // Left subtree is taller
    if ((*node)->fb < -1) {
        // Left-Right case: Left rotation on the left child, then right rotation on the current node
        if ((*node)->esq->fb > 0) {
            LL(&((*node)->esq));
        }

        // Right rotation on the current node
        RR(node);
    }
    // Right subtree is taller
    else if ((*node)->fb > 1) {
        // Right-Left case: Right rotation on the right child, then left rotation on the current node
        if ((*node)->dir->fb < 0) {
            RR(&((*node)->dir));
        }

        // Left rotation on the current node
        LL(node);
    }

    // Recursively balance the left and right subtrees
    balanceAVL(&((*node)->esq));
    balanceAVL(&((*node)->dir));
}


int atualizaFB(noAVL ** no) {
    if ((*no) == NULL) {
        return 0;
    }

    int altEsq = atualizaFB(&((*no)->esq));
    int altDir = atualizaFB(&((*no)->dir));

    (*no)->fb = altDir - altEsq;
    
    // Return the height of the node's subtree
    return (altEsq > altDir ? altEsq : altDir) + 1;
}

noAVL * procuraNo(noAVL ** raiz, noAVL * atual, char letra, int operation){
    char inicial = letra;

    while(atual->letra != inicial){
        if(atual->letra > inicial){
            if(atual->esq != NULL)
                atual = atual->esq;
            else{
                if(operation == 1){
                    noAVL * new = newNode(&atual, inicial);
                    atual->esq = new;
                    atualizaFB(raiz);
                    balanceAVL(raiz);
                    return new;
                }else{
                    return NULL;
                }
            }
        }else if(atual->letra < inicial){
            if(atual->dir != NULL)
                atual = atual->dir;
            else{
                if(operation == 1){
                    noAVL * new = newNode(&atual, inicial);
                    atual->dir = new;
                    atualizaFB(raiz);
                    balanceAVL(raiz);
                    return new;
                }else{
                    return NULL;
                }
            }
        }
    }
    return atual;
}

list * newList(char p[20]){
    list * new = (list *) malloc(sizeof(list));
    strcpy(new->palavra, p);
    new->prox = NULL;
    new->ant = NULL;
    return new;
}

int newWord(list ** lista, char p[20]){
    
    if(searchInList(lista, p) == 1){
        printf("Esta palavra já foi inserida\n");
        return 0;
    }

    list * aux;
    aux = (*lista)->prox;

    list * new = (list *) malloc(sizeof(list));
    strcpy(new->palavra, p);

    (*lista)->prox = new; 
    new->ant = (*lista);
    
    new->prox = aux;
    aux->ant = new;
    return 1;
}

int inserir(noAVL ** raiz){
    //TODO: alterar o Fator de balanceamento quando insere uma palavra.
    char palavra[20] = "oi";
    int cont = 0;
    while(palavra[0] != '0'){
        scanf("%s", palavra);
        char inicial = palavra[0];

        if((*raiz) == NULL){
            *raiz = newTree(inicial);
            (*raiz)->inicio = newList(palavra);
        }

        noAVL * atual;
        atual = *raiz;
        if(inicial == '0')
            break;
        else{
            atual = procuraNo(raiz, atual, palavra[0], 1);
            int verificador;
            verificador = newWord(&atual->inicio, palavra);
            if(verificador == 1){
                cont++;
            }
        }
    }
    printf("Todos os dados foram carregados com sucesso!!\n");

    return cont;
}

//LISTA.C SDPÇAOIGFASDÇLKJSADÇLFKJ


int getHeight(noAVL * node){
    int height = 1;
    while(node->pai != NULL){
        height += 1;
        node = node->pai;
    }
    return height;
}

void buscaPalavra(noAVL ** raiz){
    printf("Informe a palavra a ser Pesquisada:\n");
    char p[20];
    scanf("%s", p);
    noAVL * aux = procuraNo(raiz, (*raiz), p[0], 2);
    if(aux == NULL){
        printf("Palavra Inexistente!");
        return;
    }
    int height = getHeight(aux);
    if(aux != NULL){
        int teste = searchInList(&(aux->inicio), p);
        if(teste == 1){
            printf("A Palavra %s foi encontrada no NÓ '%c' nível %d\n", p, p[0], height);
        }
    }
}

void printNode(char letra, noAVL ** raiz){

    noAVL * aux = procuraNo(raiz, (*raiz), letra, 2);

    int height = getHeight(aux);

    list * atual = (*raiz)->inicio;

    while(atual != NULL){
        printf("%s\n", atual->palavra);
        if(atual->prox != NULL)
            atual = atual->prox;
        else
            break;
    } 
}

void printTree(noAVL ** raiz){
    int contador = 'A';
    do{
        procuraNo(raiz, (*raiz), contador, 2);
        printNode(contador, raiz);
        contador++;
    }while(contador != 'Z');
}

int main(){
    noAVL * raiz;

    int operand = 0;

    scanf("%d", &operand);

    if(operand == 2){
        int t = inserir(&raiz);
        printf("Total de %d palavras inseridas no dicionário\n\n", t);
    }

    while(operand != 6){
        printf("*** MENU DE OPÇÕES: ENTRE COM A OPÇÃO DESEJADA ***\n\n");
        printf("1. Pesquisa\n2. Inserção\n3. Remoção\n4. Impressão de um nó\n5. Impressão da árvore\n6. Encerrar\n\n");
        scanf("%d", &operand);

        switch (operand){
        case 1: //busca
            buscaPalavra(&raiz);
            break;
        case 2: //inserção
            int t = inserir(&raiz);
            printf("Total de %d palavras inseridas no dicionário\n\n", t);
            break;
        case 3: //remoção
            printf("Eu sou lindo\n");
            break;
        case 4: //printf nas palavras de um determinado nó 
            char letra;
            scanf("%c", letra);
            printNode(letra, &raiz);
            break;
        case 5: //imprime tudo
            printf("5\nImprimindo Árvore...\n\n");
            printTree(&raiz);
            break;
        default:
            printf("6\nPrograma Encerrado!!");
            break;
        }
    }
    return 0;
}