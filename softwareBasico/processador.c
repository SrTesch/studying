#include <stdio.h>
#include <stdlib.h>

#define byte unsigned char
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
    byte opcode;
    byte operand;
}inst;


int main(int argc, char * argv[]){
    inst program[256];
    FILE *binary_file;

    //registers
    byte acc = 0;  // accumulator
	byte pc = 0;   // program counter
	byte stat = 0; // status

    binary_file = fopen(argv[1], "rb");

    if(binary_file == NULL){
        printf("->Erro ao abrir o arquivo: %s\n", argv[1]);
        exit(0);
    }

    byte instruction[2];

    while(fread(instruction, sizeof(byte), 2, binary_file)){
        program[pc].opcode = instruction[0];
        program[pc].operand = instruction[1];
        pc++;
    }
    fclose(binary_file);

    pc = 0;
    byte memory[256];
    byte ft;
    byte opcode;
    byte operand;

    while(opcode != hlt){
        opcode =  program[pc].opcode;
        operand = program[pc].operand;

        stat = 0;
        switch(opcode){
            case load_mem:
                acc = mem[operand];
        }
    }
}

void testACC(byte acc, byte *STAT){
	byte tof;

	if (acc == 0)
		tof = 1;
	else
		tof = 0;

	uptadeSTAT(STAT, tof, ZeroACC);
}

// updates the status
void uptadeSTAT(byte *STAT, int tof, int ocz){
	if (tof)
		*STAT = *STAT | ocz; // set status to overflow, carry or 0
	else
		*STAT = *STAT & (255 - ocz); // set status = 0
}