

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compiler.h"
#define MAX_PAS_LENGTH 3000

void print_execution(int line, char *opname, int *IR, int PC, int BP, int SP, int DP, int *pas, int GP)
{
	int i;
	// print out instruction and registers
	printf("%2d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t", line, opname, IR[1], IR[2], PC, BP, SP, DP);
	
	// print data section
	for (i = GP; i <= DP; i++)
		printf("%d ", pas[i]);
	printf("\n");
	
	// print stack
	printf("\tstack : ");
	for (i = MAX_PAS_LENGTH - 1; i >= SP; i--)
		printf("%d ", pas[i]);
	printf("\n");
}

int base(int L, int BP, int *pas)
{
	int ctr = L;
	int rtn = BP;
	while (ctr > 0)
	{
		rtn = pas[rtn-1];
		ctr--;
	}
	return rtn;
}

void execute_program(instruction *code, int printFlag)
{
	// variables
	int *pas = calloc(MAX_PAS_LENGTH, sizeof(int));
	int IC, line;
	
	// read in program
	IC = 0;
	line = 0;
	while (code[line].opcode != -1)
	{
		pas[IC] = code[line].opcode;
		IC++;
		pas[IC] = code[line].l;
		IC++;
		pas[IC] = code[line].m;
		IC++;
		line++;
	}
	
	// this will print the header in the output, make sure you put your
	//		execution loop after it
	if (printFlag)
	{
		printf("\t\t\t\tPC\tBP\tSP\tDP\tdata\n");
		printf("Initial values:\t\t\t%d\t%d\t%d\t%d\n", PC, BP, SP, DP);
	}
	
	free(pas);
}
