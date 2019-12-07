

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>

#define TRUE 1 
#define FALSE 0

#define MAX_LINES 4096 
#define MAX_LINE_LEN 500 
#define MAX_LABEL_LEN 50
#define OPCODES { "add", "sub", "mul", "and" ,"or", "sll", "sra", "limm", "branch", "jal", "lw", "sw", "0ph", "1ph", "2ph","halt", ".word"} 
// all values' indices match their opcode number! "0ph", "1ph" and "2ph" are place holders so the "halt"'s index would be 15, 
// they can't be labels because they start with a digit
#define OPCODES_LEN 17 // the length of the array above 

#define REGS { "$zero", "$at", "$v0", "$a0 " ,"$a1 ", "$t0", "$t1", "$t2", "$t3", "$s0", "$s1", "$s2 ", "$gp", "$sp", "$fp","$ra"} 
// all registers' indices match their number! 
#define REGS_LEN 16 // the length of the array above 
