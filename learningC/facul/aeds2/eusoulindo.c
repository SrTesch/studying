#include <stdio.h>
#include <stdlib.h>

typedef struct cadastro{
    int age;
    char name[15];
    char cpf[11];
}cadastro;

void getFunc(cadastro * func){
    puts("Please, tell me your first name");
    scanf("%s", func->name);
    puts("Please, type your age");
    scanf("%d", &func->age);
    puts("Now, type your CPF without . and - ");
    scanf("%s", func->cpf);
};

void printFunc(cadastro * func){
    printf("Name: %s\n", func->name);
    printf("Age: %d\n", func->age);
    printf("CPF: %s\n",func->cpf);
};

int main(){
    cadastro * func1;
    func1 = (cadastro *)malloc(sizeof(cadastro));
    getFunc(func1);
    printf("\n\n\n");
    printFunc(func1);
    printf("Eu sou lindo demais\n");
    return 0;
}