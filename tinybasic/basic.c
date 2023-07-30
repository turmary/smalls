
/*  A tiny BASIC interpreter  */

#include <stdio.h>
#include <setjmp.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define NUM_LAB 100
#define LAB_LEN 10
#define FOR_NEST 25
#define SUB_NEST 25
#define PROG_SIZE 10000
#define DELIMITER 1
#define VARIABLE 2
#define NUMBER 3
#define COMMAND 4
#define STRING 5
#define QUOTE 6

#define PRINT 1
#define INPUT 2
#define IF 3
#define THEN 4
#define FOR 5
#define NEXT 6
#define TO 7
#define GOTO 8
#define EOL 9
#define FINISHED 10
#define GOSUB 11
#define RETURN 12
#define END 13
#define REM 14

char *prog;			/* holds expression to be analyzed  */
jmp_buf e_buf;			/* hold environment for longjmp() */

int variables[26] = {		/* 26 user variables,A-Z  */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0
};

struct commands {		/* keyword lookup table  */
	char command[20];
	char tok;
} table[] = {			/* command must be entered lowercase  */
	"print", PRINT,		/* in this table  */
	"input", INPUT,
	"if", IF,
	"then", THEN,
	"goto", GOTO,
	"for", FOR,
	"next", NEXT,
	"to", TO,
	"gosub", GOSUB,
	"return", RETURN,
	"end", END,
	"rem", REM,
	NULL, END
};

char token[80];
char token_type, tok;

struct label {
	char name[LAB_LEN];
	char *p;		/* point to place to go in source */
};

struct label label_table[NUM_LAB];
char *find_label(), *gpop();

struct for_stack {
	int var;		/* counter variable  */
	int target;		/* target value  */
	char *loc;
} fstack[FOR_NEST];		/* stack for FOR/NEXT loop  */
struct for_stack fpop();

char *gstack[SUB_NEST];		/* stack for gosub  */
int ftos;			/* index to top of FOR stack  */
int gtos;			/* index to top of GOSUB  */

void print(), scan_labels(), find_eol(), exec_goto();
void gosub(), greturn(), gpush(), label_init(), fpush();

/* Load a program */
load_program(char *p, char *fname)
{
	FILE *fp;
	int i = 0;

	if (!(fp = fopen(fname, "rb")))
		return 0;

	i = 0;
	do {
		*p = getc(fp);
		p++;
		i++;
	} while (!feof(fp) && i < PROG_SIZE);
	*(p - 1) = '\0';	/* null terminate the program  */
	fclose(fp);
	return 1;
}


/* comment a line */
void rem()
{
	find_eol();
}


/* assign a variable a value */
void assignment()
{
	int var, value;

	/* getthe variable name */
	get_token();
	if (!isalpha(*token)) {
		serror(4);
		return;
	}

	var = toupper(*token) - 'A';

	/* get the equals sign */
	get_token();
	if (*token != '=') {
		serror(3);
		return;
	}

	/* get the value to assign to var */
	get_exp(&value);

	/* assign the value */
	variables[var] = value;
}


/* execute a simple version of the BASIC PRINT statement */
void print()
{
	int answer;
	int len = 0, spaces;
	char last_delim;

	do {
		get_token();	/* get next list item */
		if (tok == EOL || tok == FINISHED || tok == REM)
			break;
		if (token_type == QUOTE) {	/* is string  */
			printf("%s", token);
			len += strlen(token);
			get_token();
		} else {	/* is expression  */
			putback();
			get_exp(&answer);
			get_token();
			len += printf("%d", answer);
		}
		last_delim = *token;
		
		if (*token == ',') {
			/* compute number of move to next tab */
			spaces = 8 - (len % 8);
			len += spaces;	/* add in the tabbing position */
			while (spaces) {
				printf(" ");
				spaces--;
			}
		} else if (*token == ';') {
			printf("  ");
		} else if (tok != EOL && tok != FINISHED && tok != REM)
			serror(0);
	} while (*token == ';' || *token == ',');

	if (tok == EOL || tok == FINISHED) {
		if (last_delim != ';' && last_delim != ',')
			printf("\n");
	} else if (tok != REM) {
		serror(0);	/* error is not, or ; */
	}
}


/* find all labels */
void scan_labels()
{
	int addr;
	char *temp;

	label_init();		/* zero all labels */
	temp = prog;		/* save poiter to top of program */

	/* if the first token in the fike is a label */
	get_token();
	if (token_type == NUMBER) {
		strcpy(label_table[0].name, token);
		label_table[0].p = prog;
	}

	find_eol();
	do {
		get_token();
		if (token_type == NUMBER) {
			addr = get_next_label(token);
			if (addr == -1 || addr == -2) {
				(addr == -1) ? serror(5) : serror(6);
			}
			strcpy(label_table[addr].name, token);
			label_table[addr].p = prog;	/* current point in program */
		}
		/* if not on a blank line , find next line */
		if (tok != EOL)
			find_eol();
	} while (tok != FINISHED);
	prog = temp;		/* restore to original */
}


/* find the start of next line */
void find_eol()
{
	/*while (*prog != '\n' && *prog != '\0')
		++prog;
	if (*prog)
		prog++;*/
	while ((token_type != DELIMITER) || (tok != EOL && tok != FINISHED)) {
		get_token();
		/* printf("%d %d %s\n", token_type, tok, token)*/
	}
}


/* return index of next free posion in the label array
      -1 is returned if the array is full.
      -2 is returned when duplicate label is found.
*/
get_next_label(char *s)
{
	register int t;

	for (t = 0; t < NUM_LAB; ++t) {
		if (label_table[t].name[0] == 0)
			return t;
		if (!strcmp(label_table[t].name, s))
			return -2;	/* dup */
	}
	return -1;
}

/* find location of given label. A null is returned if
   label is not found; ohtherwise a pointer to the position
   of the label is returned.
*/
char *find_label(char *s)
{
	register int t;

	for (t = 0; t < NUM_LAB; ++t)
		if (!strcmp(label_table[t].name, s))
			return label_table[t].p;
	return '\0';		/* error condition */
}


/* execute a GOTO statement. */
void exec_goto()
{
	char *loc;

	get_token();		/* get label to go to */
	/* find the location of label */
	loc = find_label(token);
	if (loc == '\0')
		serror(7);	/* label not defined */
	else
		prog = loc;	/* start program running at that time */
}


/* initialize the array that holds the labels.
   by convention , a null label name indicates that
   array posiiton is unused.
*/
void label_init()
{
	register int t;

	for (t = 0; t < NUM_LAB; ++t)
		label_table[t].name[0] = '\0';
}


/* execute an IF statement */
void exec_if()
{
	int x, y, cond;
	char op;

	get_exp(&x);		/* get left exapression */

	get_token();		/* get the operator */
	if (!strcmp("<>", token)) {
		serror(0);	/* not a leagal oprator */
		return;
	}
	op = *token;
	get_exp(&y);		/* get right expression */

	/* determine the outcome */
	cond = 0;
	switch (op) {
	case '<':
		if (x < y)
			cond = 1;
		break;
	case '>':
		if (x > y)
			cond = 1;
		break;
	case '=':
		if (x == y)
			cond = 1;
		break;
	}
	if (cond) {		/* is true so process target of IF */
		get_token();
		if (tok != THEN) {
			serror(8);
			return;
		}		/* else program execution starts on next line */
	} else
		find_eol();	/* find start of next line */
}


/* execute a FOR loop */
void exec_for()
{
	struct for_stack i;
	int value;

	get_token();		/* read the control variable */
	if (!isalpha(*token)) {
		serror(4);
		return;
	}

	i.var = toupper(*token) - 'A';	/* save its index */

	get_token();		/* read the equal sign */
	if (*token != '=') {
		serror(3);
		return;
	}
	get_exp(&value);	/* get initial value */

	variables[i.var] = value;

	get_token();

	if (tok != TO)
		serror(9);	/* read an discard the TO */
	get_exp(&i.target);	/* get target value */

	/* if loop can execute at least once, push into on stack */
	if (value <= i.target) {
		i.loc = prog;
		fpush(i);
	} else			/* otherwise, skip loop code altogether */
		while (tok != NEXT)
			get_token();
}


/* execute a NEXT statement */
void next()
{
	struct for_stack i;

	i = fpop();		/*read the loop info */

	variables[i.var]++;	/* increment control variable */
	if (variables[i.var] > i.target)
		return;		/* all done */
	fpush(i);		/* otherwise,return the info */
	prog = i.loc;		/* loop */
}


/* push function for the FOR stack */
void fpush(struct for_stack i)
{
	if (ftos > FOR_NEST)
		serror(10);
	fstack[ftos] = i;
	ftos++;
}


struct for_stack fpop()
{
	ftos--;
	if (ftos < 0)
		serror(11);
	return (fstack[ftos]);
}


/* exec a simple form of BASIC INPUT command */
void input()
{
	char str[80], var;
	int i;

	get_token();		/* see if prompt string id=s present */
	if (token_type == QUOTE) {
		printf(token);	/* if so , print it and check for command */
		get_token();
		if (*token != ',')
			serror(1);
		get_token();
	} else
		printf("? ");	/* otherwise, prompt with / */
	var = toupper(*token) - 'A';	/* get the input var */

	scanf("%d", &i);	/* read input */
	variables[var] = i;	/* store it */
}


/* execute a GOSUB command */
void gosub()
{
	char *loc;

	get_token();
	/* find the label to call */
	loc = find_label(token);
	if (loc == '\0')
		serror(7);	/* label not defined */
	else {
		gpush(prog);	/* save place to return to */
		prog = loc;	/* start program running at that loc */
	}
}


/* return from GOSUB */
void greturn()
{
	prog = gpop();
}


/* GOSUB stack push function */
void gpush(char *s)
{
	gtos++;

	if (gtos == SUB_NEST) {
		serror(12);
		return;
	}

	gstack[gtos] = s;
}


/* GOSUB stack pop function */
char *gpop()
{
	if (gtos == 0) {
		serror(13);
		return 0;
	}
	return gstack[gtos--];
}

main(int argc, char *argv[])
{
	char in[80];
	int answer;
	char *p_buf;
	char *t;

	if (argc != 2) {
		printf("usage: run <filename>\n");
		exit(1);
	}

	/* allocate memory for the program */
	if (!(p_buf = (char *) malloc(PROG_SIZE))) {
		printf("allocation failure");
		exit(1);
	}

	/* load the program to execute */
	if (!load_program(p_buf, argv[1]))
		exit(1);

	if (setjmp(e_buf))
		exit(1);	/* initialize the long jump */

	prog = p_buf;
	scan_labels();		/* find the labels in the program  */
	ftos = 0;		/* initialize the FOR stack index  */
	gtos = 0;		/* initialize the GOSUB stack index */
	do {
		token_type = get_token();
		/* check for assignment stack */
		if (token_type == VARIABLE) {
			putback();	/* return the varto the input stream */
			assignment();	/* must 1: assignment statemnet  */
		} else if (token_type == NUMBER) {	/* a line # */
			/* printf("%s# ", token); */
		} else		/* is command */
			switch (tok) {
			case PRINT:
				print();
				break;
			case GOTO:
				exec_goto();
				break;
			case IF:
				exec_if();
				break;
			case FOR:
				exec_for();
				break;
			case NEXT:
				next();
				break;
			case INPUT:
				input();
				break;
			case GOSUB:
				gosub();
				break;
			case RETURN:
				greturn();
				break;
			case END:
				exit(0);
				break;
			case REM:
				rem();
				break;
			}
	} while (tok != FINISHED);
}
