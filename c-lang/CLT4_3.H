#include <stdio.h>
#include <ctype.h>
#include "clt4_4.h"

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
