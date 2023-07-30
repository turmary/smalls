/*
   recursive descent parser for integer expression
   which may include variables
*/

#include <stdio.h>
#include <setjmp.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define DELIMITER 1
#define VARIABLE 2
#define NUMBER 3
#define COMMAND 4
#define STRING 5
#define QUOTE 6
#define REM 14

#define EOL 9
#define FINISHED 10

extern char *prog;		/* holds expression to be analyzed */

extern jmp_buf e_buf;		/* hold enviroment */
extern int variables[26];	/* variables */
extern struct commands {
	char command[20];
	char tok;
} table[];

extern char token[80];		/* holds string representation of token */
extern char token_type;		/* contains type of token */
extern char tok;		/* holds the internal representation of token */

void get_exp(), level2(), level3(), level4(), level5();
void level6(), primitive();     /* , arith(), unary(); */
int iswhite (char c);
int isdelim (char c);
void arith(char o,int *r,int *h);
void unary(char o,int *r);
void serror(), putback();


/* entry point into parser */
void get_exp(int *result)
{
	get_token();
	if (!*token) {
		serror(2);
		return;
	}
	level2(result);
	putback();		/*return last token read to input stream */
}


/* add or subtract two terms */
void level2(int *result)
{
	register char op;
	int hold;

	level3(result);
	while ((op = *token) == '+' || op == '-') {
		get_token();
		level3(&hold);
		arith(op, result, &hold);
	}
}


/* multiply or divide two factors */
void level3(int *result)
{
	register char op;
	int hold;

	level4(result);
	while ((op = *token) == '*' || op == '/' || op == '%') {
		get_token();
		level3(&hold);
		arith(op, result, &hold);
	}
}


/* process integer exponent */
void level4(int *result)
{
	register char op;
	int hold;

	level5(result);
	if ((op = *token) == '^') {
		get_token();
		level4(&hold);
		arith(op, result, &hold);
	}
}


/* is a unary + or - */
void level5(int *result)
{
	register char op;

	op = 0;
	if ((token_type == DELIMITER) && *token == '+' || *token == '-') {
		op = *token;
		get_token();
	}
	level6(result);
	if (op)
		unary(op, result);
}


/* process parenthesized expression */
void level6(int *result)
{
	if ((*token == '(') && (token_type == DELIMITER)) {
		get_token();
		level2(result);
		if (*token != ')')
			serror(1);
		get_token();
	} else
		primitive(result);
}


/* find value of number or variable */
void primitive(int *result)
{
	switch (token_type) {
	case VARIABLE:
		*result = find_var(token);
		get_token();
		return;
	case NUMBER:
		*result = atoi(token);
		get_token();
		return;
	default:
		serror(0);
	}
}


/* perform the specified arithmetic */
void arith(char o, int *r, int *h)
{
	register int t, ex;

	switch (o) {
	case '-':
		*r = *r - *h;
		break;
	case '+':
		*r = *r + *h;
		break;
	case '*':
		*r = *r ** h;
		break;
	case '/':
		*r = (*r) / (*h);
		break;
	case '%':
		*r = (*r) % (*h);
		break;
	case '^':
		ex = *r;
		if (*h == 0) {
			*r = 1;
			break;
		}
		for (t = (*h) - 1; t > 0; --t)
			*r = (*r) * ex;
		break;
	}
}


/* reverse the sign */
void unary(char o, int *r)
{
	if (o == '-')
		*r = -(*r);
}


/* find the value of a variable */
int find_var(char *s)
{
	if (!isalpha(*s)) {
		serror(4);	/* not a variable */
		return 0;
	}
	return variables[toupper(*token) - 'A'];
}


/* display an error message */
void serror(int error)
{
	char *e[] = {
		"syntax error",
		"unbalanced parentheses",
		"no expression present",
		"equal sign expected",
		"not a variable",
		"label table full",
		"duplicate label",
		"undefined label",
		"THEN expected",
		"TO expected",
		"too many nested FOR loops",
		"NEXT without FOR",
		"too many nested GOSUB",
		"RETURN without GOSUB"
	};

	printf("T:%s(%d) %s\n", token, tok, e[error]);
	longjmp(e_buf, 1);	/* return to save point */
}


/* get a token */
get_token()
{
	register char *temp;

	token_type = 0;
	tok = 0;
	temp = token;

	if (*prog == '\0') {	/* end of file */
		*token = 0;
		tok = FINISHED;
		return (token_type = DELIMITER);
	}

	while (iswhite(*prog))
		++prog;		/* skip over white space */

	if (*prog == '\r' || *prog == '\n') {	/* CR LF */
		if (*prog == '\r') {
			*temp++ = *prog;
			++prog;
		}
		if (*prog == '\n') {
			*temp++ = *prog;
			++prog;
		}
		tok = EOL;
		*temp = 0;
		return (token_type = DELIMITER);
	}

	if (strchr("+-*^/%=;(),><", *prog)) {	/* delimiter */
		*temp = (*prog);
		prog++;		/* advance to next position */
		temp++;
		*temp = 0;
		return (token_type = DELIMITER);
	}

	if (*prog == '"') {	/* quote string */
		prog++;
		while (*prog != '"' && *prog != '\r' && *prog != '\n')
			*temp++ = (*prog++);
		if (*prog == '\r' || *prog == '\n')
			serror(1);
		prog++;
		*temp = 0;
		return (token_type = QUOTE);
	}

	if (isdigit(*prog)) {	/* number */
		while (!isdelim(*prog))
			*temp++ = (*prog++);
		*temp = '\0';
		return (token_type = NUMBER);
	}

	if (*prog == '\'') {
		*temp++ = (*prog++);	/* advance to next position */
		*temp = 0;
		tok = REM;
		return (token_type = COMMAND);
	}

	if (*prog == ':') {	/* : follow a new line */
		*temp++ = (*prog++);	/* advance to next position */
		*temp = 0;
		tok = EOL;
		return (token_type = DELIMITER);
	}

	if (isalpha(*prog)) {	/* var or command */
		while (!isdelim(*prog))
			*temp++ = *prog++;
		token_type = STRING;
	}

	*temp = '\0';

	/* see if a string is a command or a variable */
	if (token_type == STRING) {
		tok = look_up(token);	/* convert to internal rep */
		if (!tok)
			token_type = VARIABLE;
		else
			token_type = COMMAND;	/* is a command */
	}
	return token_type;
}


/* return a token to input stream */
void putback()
{
	char *t;
	t = token;
	for (; *t; t++)
		prog--;
}


look_up(char *s)
{
	register int i, j;
	char *p;

	/* convert to lowercase */
	p = s;
	while (*p) {
		*p = tolower(*p);
		p++;
	}

	/* see if token is in table */
	for (i = 0; *table[i].command; i++)
		if (!strcmp(table[i].command, s))
			return table[i].tok;
	return 0;		/* unknown command */
}


/* return true if c is a delimiter */
isdelim(char c)
{
	if (strchr("\':;,+-<>/*%^=() \n", c) || c == 9 || c == '\r' || c == 0)
		return 1;
	return 0;
}


iswhite(char c)
{
	if (c == ' ' || c == '\t')
		return 1;
	else
		return 0;
}
