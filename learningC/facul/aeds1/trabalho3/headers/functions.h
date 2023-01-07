#ifndef __functions.h
#define __functions.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

/**@brief Esta função serve para facilitar a leitura dos outputs ao usuário! Apertando o Enter para voltar ao menu principal
*/
void enterVoltar(); 


/**@brief Esta função é chamada no começo do programa e serve para criar toda a lista que vai simular a memória, ja alocando todos os espaços que serão ocupados desde o começo até o fim do programa
*/
no **criarLista();


/**@brief Esta função é chamada para inserir o conteúdo de um arquivo em um bloco que esteja livre!
*@param inicio É um inteiro que indica o indice de onde começar a busca (este é guardado em uma variável auxiliar para conseguir acessar o ultimo indice em que o arquivo foi inserido e apontar para o atual)
*@param text é o conteúdo a ser inserido
*@param lista é o array que simula a memória
*/
int inserir(int inicio, char *text, no ** lista);


/**@brief Esta função serve para ler e inserir um arquivo que o usuário deseje! Retorna um inteiro que indica quantos blocos foram usados na memória

*@param lista é um arrayque simula a memória
*@param espacos_livres é a quantidade de blocos livres que vai servir pra indicar se é possível ou não inserir um arquivo.
*@param lista_arq é um array que contém o nome de todos os arquivos, logo deverá ser acrescentado o nome e metadados do arquivo que for inserido
*/
int ler_arq(no **lista, int espacos_livres, arquivo ** lista_arq);


/**@brief Esta função serve para encontrar o endereço de um determinado arquivo
*@param lista_arq É um array contendo todos os metadados dos arquivos que ja estão inseridos no programa!
*@param lista_arq É o nome do arquivo que o usuário deseja encontrar.
*/
int end_arq(arquivo ** lista_arq, char *arq);

/**@brief Esta função serve para remover algum arquivo que ja esteja na simulação de memória
*@param lista_arq Lista com metadados de todos os arquivos
*@param lista É um array que simula a memória
*/
int remover_arq(arquivo ** lista_arq, no **lista);


/**@brief Esta função serve para Buscar um arquivo específico em que o usuário desejar.
*@param lista_arq Lista com metadados de todos os arquivos
*@param lista É um array que simula a memória
*/
void imprimir_arq(arquivo ** lista_arq, no **lista);


/**@brief Esta função serve para mostrar todos os dados que estão armazenados na memória
*@param lista_arq Lista com metadados de todos os arquivos
*@param lista É um array que simula a memória
*/
void imprimir_lista(arquivo ** lista_arq, no ** lista);

/**@brief Esta função serve para buscar um termo específico e imprimi quantas ocorrências deste termo ocorre em cada arquivo.
*@param lista_arq Lista com metadados de todos os arquivos
*@param lista É um array que simula a memória
*/
void buscar_termo(arquivo ** lista_arq, no ** lista);

/**@brief função auxiliar que verifica se uma string está contida na outra e retorna -1 caso nao ocorra ou caso esteja contida, retorna a ultima posição que foi verificada
*@param str1 é a string a ser verificada
*@param str2 é o termo a ser verificado
*@param indice é a posição em que deve-se começar a verificação
*/
int existe(char *str1, char *str2, int indice);

#endif