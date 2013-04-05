#include <stdio.h>
#include <ctype.h>
#include <limits.h>

#define D_S_MAIN 1
#define D_S 1

#if D_S
void strclr(void);
#endif
void reverse(char s[]);
char* itoa(int, char *);
int strindex(char * s, char * t);

/*read a line and return the length of it*/
int getline(char* s){
	int c, i;

	for(i = 0; (c = fgetc(stdin)) != EOF && c != '\n'; ++i)
		*s++ = c;
	if(c == '\n' || c == EOF)
		*s++ = c;
	*s = '\0';
	return i;
}

void reverse(char* s){
	int c;
	char *pi, *pj;

	for(pi = s, pj = s + strlen(s)-1; pi < pj; pi++, pj--){
		c = *pi; *pi = *pj; *pj = c;
	}
}


char* itoa(int n, char * si){
	char* s = si;
	int i, sign, signMin = 0;

	if((sign = n) < 0)
		if(n != INT_MIN)
			n = -n;
		else{
			signMin = 1;
			n = - (n + 1);
		}
	i = 0;
	do{
		*s++ = n % 10 + '0';
	}while((n /= 10) > 0);
	if(sign < 0)
		*s++ = '-';
	if(signMin)
		(*si)++;
	*s = '\0';
	reverse(si);
	return si;
}

int strindex(char * s, char * t){
	int i, j, k;

	for(i = strlen(s)-strlen(t)+1; i >= 0; i--){
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if(k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

#define D_SH 0
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if(bufp >= BUFSIZE)
		printf("ungetch: too many charactors\n");
	else
		buf[bufp++] = c;
}

#define NUMBER '0'
#define SIN 0x101
#define COS 0x102
#define POW 0x103
#define GETVAR 0x201
#define SETVAR 0x202

int getop(char *s){
	int i, c, nc;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(c == '#' || c == '@'){
		s[1] = getch();
		s[2] = '\0';
		if(c == '#')
			return GETVAR;
		else
			return SETVAR;
	}else if(c == 's' || c == 'c' || c == 'p'){
		scanf("%s", &s[1]);
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
	else if(c == '-' && isspace(nc = getch()))
		return '-';
	else if(c == '-')
		ungetch(c = nc);
	i = 0;
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

#if D_S_MAIN
int main() {
	int i;
	char b[80] = "Hello\0Morning!\n";

	clrscr();
	i = getline(b);
	printf("\nThe line geted %d chars\n\t%s", i, b);
	reverse(b);
	printf("\nAfter reverse(b) b = %s", b);
	printf("\nConvert to string = %s", itoa(3852, b));
	return 0;
}
#endif
