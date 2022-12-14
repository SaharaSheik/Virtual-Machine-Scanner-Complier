

typedef enum token_type {
	constsym = 1, varsym, procsym, dosym, odsym, whilesym, whensym, 
	elsedosym, callsym, writesym, readsym, identsym, numbersym, assignsym, 
	addsym, subsym, multsym, divsym, modsym, eqlsym, neqsym, 
	lsssym, leqsym, gtrsym, geqsym, oddsym, lparensym, rparensym, 
	commasym, periodsym, semicolonsym
} token_type;

typedef struct lexeme {
	char name[12];
	int value;
	token_type type;
} lexeme;

typedef struct instruction {
	int opcode;
	int l;
	int m;
} instruction;

typedef struct symbol {
	int kind;
	char name[12];
	int val;
	int level;
	int addr;
	int mark;
} symbol;

lexeme *lexanalyzer(char *input, int printFlag);
instruction *parse(lexeme *list, int printTable, int printCode);
void execute_program(instruction *code, int printFlag);
