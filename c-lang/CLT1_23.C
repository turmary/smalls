#include <stdio.h>

#define D_S 1         /* debug sign 'here \' good*/
void powQuote(int);   /* print all chars between two Quotes "  "*"/"\" */
void powRem();        /* process all Rem in programs */
char* String = "Hell' /' \"/*o Wo*/r\' '\"/*ld*/\n";

int main(){
	int c, lc;

	lc = '\n';
	while(EOF != lc){
		c = getchar();
		if('/' == lc && '*' == c){
			powRem();
			c = getchar();
		}else if(('\'' == c || '\"' == c) && lc != '\\'){
			putchar(lc);
			powQuote(c);
			c = getchar();
		}else
			putchar(lc);
		lc = c;
	}
	return 0;
}

void powQuote(int bc){
	int c, lc = bc;

	putchar(lc);
	while(EOF != lc){
		putchar(c = getchar());
		if(c == bc && lc != '\\')
			return;
		lc = c;
	}
}

void powRem(int lc){
	int c;

	while(EOF != lc){
		c = getchar();
		if('*' == lc && '/' == c)
			return;
		else
			;
		lc = c;
	}
}
