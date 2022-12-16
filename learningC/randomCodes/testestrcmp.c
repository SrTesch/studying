#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char oi[5], eu[5];
        scanf("%s", oi);
        scanf("%s", eu);
    while(strcmp(oi,eu)){
        puts("São iguais");
        scanf("%s", oi);
        scanf("%s", eu);
    }
    return 0;
}