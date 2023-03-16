#include <stdio.h>

#define byte "NãoSei"
#define load_mem 0
#define load_val 1
#define store    2
#define add      3
#define sub      4
#define mul      5
#define div      6
#define inc      7
#define dec      8
#define and      9
#define or       10
#define not      11
#define jmp      12
#define jz       13
#define jnz      14
#define jg       15
#define jl       16
#define jge      17
#define jle      18
#define hlt      19

typedef struct __inst{
    int opcode;
    int operand;
}inst;


// argC argV
int main(int argc, char ** argv){
    inst programa[256];
}