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
//definindo flags
#define zeroacc  1
#define carry    2
#define overflow 4


typedef struct __inst{
    byte opcode;
    byte operand;
}inst;

void updateSTAT(byte *stat, byte acc, int ocz){
    if(!acc){
        *stat = 1;
        return;
    }

    *stat = *stat | ocz;
}

int main(int argc, char * argv[]){
    inst program[256];
    FILE *binary_file;

    //registers
    byte acc = 0;  // accumulator
	byte pc = 0;   // program counter
	byte stat = 0; // status

    //Reading file
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


    //start instructions
    pc = 0;
    byte memory[256];
    byte opcode;
    byte operand;

    while(opcode != hlt){
        opcode =  program[pc].opcode;
        operand = program[pc].operand;

        switch(opcode){
        case load_mem:
            acc = memory[operand];
            updateSTAT(&stat, acc, zeroacc);
            pc++;
        break;

		case load_val:
			acc = operand;
            updateSTAT(&stat, acc, zeroacc);
			pc++;
			break;

		case store:
			memory[operand] = acc;
			pc++;
			break;

		case add:
			// checks for carry
			if ((int)(acc + memory[operand]) > 255)
			    updateSTAT(&stat, acc, carry);
			else
                updateSTAT(&stat, acc, 0);

			acc += memory[operand];
			pc++;
			break;

		case sub:
			acc -= memory[operand];
			updateSTAT(&stat, acc, 0);
			pc++;
			break;

		case mul:
			// checks for overflow
			if ((int)(acc * memory[operand]) > 255)
			    updateSTAT(&stat, acc, overflow);
			else
                updateSTAT(&stat, acc, 0);

			acc *= memory[operand];
			pc++;
			break;

		case div:
			acc /= memory[operand];
			updateSTAT(&stat, acc, 0);
			pc++;
			break;

		case inc:
			// checks for carry
			if ((int)(acc + 1) > 255)
			    updateSTAT(&stat, acc, carry);
			else
                updateSTAT(&stat, acc, 0);

			++acc;
			pc++;
			break;

		case dec:
			--acc;
			updateSTAT(&stat, acc, 0);
			pc++;
			break;

		case and:
			acc &= memory[operand];
			updateSTAT(&stat, acc, 0);
			pc++;
			break;

		case or:
			acc |= memory[operand];
			updateSTAT(&stat, acc, 0);
			pc++;
			break;

		case not:
			acc = ~acc;
			updateSTAT(&stat, acc, 0);
			pc++;
			break;

		case jmp:
			pc = operand;
			break;

		case jz:
			if (acc = 0)
				pc = operand;
			else
				pc += 1;
			break;

		case jnz:
			if (acc != 0)
				pc = operand;
			else
				pc += 1;
			break;

		case jg:
			if (acc > 0)
				pc = operand;
			else
				pc += 1;
			break;

		case jl:
			if (acc < 0)
				pc = operand;
			else
				pc += 1;
			break;

		case jge:
			if (acc >= 0)
				pc = operand;
			else
				pc += 1;
			break;

		case jle:
			if (acc <= 0)
				pc = operand;
			else
				pc += 1;
			break;

		case hlt:
			printf("ACC: %d\nSTAT: %.2X\n", acc, stat);
            break;
        }
    }
    return 0;
}