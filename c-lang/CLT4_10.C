#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define D_S_MAIN 1

#define MAXVAL 100
static int sp = 0;
static double val[MAXVAL];

/*read a line and return the length of it*/
int getline(int s[]){
	int c, i;

	for(i = 0; (c = fgetc(stdin)) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n' || c == EOF)
		s[i++] = c;
	s[i] = '\0';
	return i;
}

void push(double f){
	if(sp < MAXVAL){
		val[sp++] = f;
#if D_S_STACK
		printf("PUSH TOP=%10.6f\n", f);
#endif
	}else
		printf("error: stack full, can't push %g\n in push()", f);
}

double getTop(void){
	if( sp > 0){
		return val[sp - 1];
	}else{
		printf("error: stack empty in getTop()\n");
		return -1;
	}
}

double pop(void){
	if(sp > 0){
#if D_S_STACK
		printf("GET TOP=%10.6f\n", val[sp-1]);
#endif
		return val[--sp];
	}else{
		printf("error: stack empty in pop()\n");
		return -1;
	}
}

#define BUFSIZE 256

int buf[BUFSIZE], bufp = 0;

#define MAXOP 100
#define NUMBER '0'
#define SIN 0x101
#define COS 0x102
#define POW 0x103
#define GETVAR 0x201
#define SETVAR 0x202

int getop(char *s){
	int i, j, c, nc;

	while((s[0] = c = buf[bufp++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(c == '#' || c == '@'){
		s[1] = buf[bufp++];
		s[2] = '\0';
		if(c == '#')
			return GETVAR;
		else
			return SETVAR;
	}else if(c == 's' || c == 'c' || c == 'p'){
		for(j = 1; j < MAXOP; j++)
			if(!isalpha(s[j] = buf[bufp++]))
				break;
		s[++j] = '\0';
		switch(c){
		case 's':
			return SIN;
		case 'c':
			return COS;
		case 'p':
			return POW;
		default:
			printf("error: function error in getop()\n");
			break;
		}
	}else if(!isdigit(c) && c != '.' && c != '-')
		return c;
	else if(c == '-' && isspace(nc = buf[bufp++]))
		return '-';
	else if(c == '-')
		buf[--bufp] = (c = nc);
	i = 0;
	if(isdigit(c))
		while(isdigit(s[++i] = c = buf[bufp++]))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = buf[bufp++]))
			;
	s[++i] = '\0';
	if(c != EOF)
		buf[--bufp] = c;
	return NUMBER;
}

#define D_S 0

#if D_S
void clrscr(void);
#endif

int getop(char *);
void push(double);
double pop(void);

#if D_S_MAIN
int main(){
	int	type;
	double	op2, var[26];
	char	s[MAXOP];

	clrscr();
	getline(buf);
	while((type = getop(s)) != EOF){
#if D_S
		printf("s in getop(s) = %s\n", s);
#endif
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
			getline(buf);
			bufp = 0;
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