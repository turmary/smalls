#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "clt4_3.h"
#define D_S 1

#if D_S
void clrscr(void);
#endif

#define MAXOP 100

int getop(char *);
void push(double);
double pop(void);

#if D_S
int main(){
	int	type;
	double	op2, var[26];
	char	s[MAXOP];

	clrscr();
	while((type = getop(s)) != EOF){
		switch(type){
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if(op2 != 0.0)
				push((int)pop() % (int)op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		case SIN:
			push(sin(pop()));
			break;
		case COS:
			push(cos(pop()));
			break;
		case POW:
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case GETVAR:
			var[s[1]-'a'] = getTop();
			break;
		case SETVAR:
			push(var[s[1]-'a']);
			break;
		/*case '=':
			printf("\t%.8g\n", getTop());
			break;
		*/
		default:
			printf("error: unknown command %s \n", s);
			break;
		}
	}
	return 0;
}
#endif