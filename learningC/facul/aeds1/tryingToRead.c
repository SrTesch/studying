#include <stdio.h>
 
#define MAX_LINE_LENGTH 20
 
int main() {
    FILE *textfile;
    char line[MAX_LINE_LENGTH];
     
    textfile = fopen("arquivo.txt", "r");
    if(textfile == NULL)
        printf("Arquivo vazio ou Não encontrado\n");
     
    while(fgets(line, MAX_LINE_LENGTH, textfile)){
        printf(line);
    }
     
    fclose(textfile);
    return 0;
}