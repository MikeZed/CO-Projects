

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>

#define TRUE 1 
#define FALSE 0

#define MAX_LINES 4096 
#define MAX_LINE_LEN 500 
#define MAX_LABEL_LEN 50
#define OPCODES { "add", "sub", "mul", "and" ,"or", "sll", "sra", "limm", "branch", "jal", "lw", "sw", "0ph","1ph","2ph","halt", ".word"} 
// all values match their opcode number! "0ph", "1ph" and "2ph" are place holders so the "halt"'s index would be 15, they can't be labels because they start with a digit
#define OPCODES_LEN 17 // the length of the array above 


typedef	struct label {

	char name[MAX_LABEL_LEN];
	int address;

} Label;


void read_file();
int return_value();
int get_instruction(); 
int get_opcode();

int main(int argc, char** argv)
{

	FILE * ASM_file = NULL; 
	FILE * MEMIN = NULL; 

	Label* Labels[MAX_LINES];

//	for (int i = 0; i < argc; i++)
//	{
//		printf("%s\n", argv[i]);
//	}
	
	ASM_file = fopen(argv[2], "r");
	MEMIN = fopen(argv[3], "w");

	if (ASM_file == NULL || MEMIN == NULL)
	{
		printf("Couldn't open file, terminating process\n");
		exit(1); 
	}

	// read file, perform first pass 
	read_file(ASM_file, Labels, 1, NULL); 

	// read file, perform second pass 
	read_file(ASM_file, Labels, 2, MEMIN);

	fclose(ASM_file);
	fclose(MEMIN);

	return 0; 
}


// performs first pass over the code
// to get the labels and their addresses
void read_file(FILE* asm_file, Label* Labels[], int pass_num, FILE* out_file)
{

	char line[MAX_LINE_LEN];
	char* delim = " \n\t,:";    // line delimiters 

	char* token;               // a token, will hold part of the line
	int comment_start = FALSE; // if a token contains '#' it means a comment has started

	char* number_sign_index = NULL;

	int PC = 0;				   // current PC 

	int i = 1;
	
	while (fgets(line, MAX_LINE_LEN, asm_file) != NULL && i<100) // read file line by line 
	{
		token = strtok(line, delim); // get first token in line

		int a= return_value(token);
		printf(" %d %s \n", a, token);

		while (token != NULL && *token != '#')
		{

			number_sign_index = strchr(token, '#'); // number_sign - '#', holds address of '#' in token if exists

			if (number_sign_index != NULL)  // check if token has '#'
			{
				*number_sign_index = '\0';  // truncate token 
				comment_start = TRUE;       // indicates that after current token a comment has started
			}

			// do stuff with token 










			// first pass - get labels
			if (pass_num == 1)
			{
				//check_label();

			}
			// second pass - get instructions in hex and write in file 
			else
			{



				
			}














			// end 

			
			if (comment_start) // if a comment has started -> read next line 
				break;

			token = strtok(NULL, delim); // read next token 
			
		}
	}
}


// a line starts with label, an opcode or ".word"
// the function recieves the first word in the line and returns:
// its opcode number if its an opcode,
// 16 if it's ".word",
// -1 if it's  a label and 0 if it's NULL 
int return_value(char* line_start)
{
	char* opcodes[] = OPCODES;
	
	if (line_start == NULL) return 0; 

	for (int i = 0; i < OPCODES_LEN; i++)
	{
		if (strcmp(line_start, opcodes[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}

// recieves opcode str, returns opcode number in hex 
int get_opcode()
{



}

// recieves register str, returns register number in hex 
int get_reg()
{



}


int get_instruction();




	