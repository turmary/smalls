/* tary, 2013-06-06 18:00 */
%start foo_start
%token ADDOP MULTOP NUMBER OPEN_BRAC CLOSE_BRAC

%left ADDOP
%left MULTOP

%%
foo_start : expr { printf("the value of the expression is %d\n", $1); }

expr : OPEN_BRAC expr CLOSE_BRAC { $$ = $2; }
	| expr ADDOP expr { $$ = $1 + $3; }
	| expr MULTOP expr { $$ = $1 *  $3; }
	| NUMBER { $$ = $1; }
	;

%%
/* start program */
#include <stdio.h>
#include "lex.yy.c"

int main(int argc, char* argv[]) {
	return yyparse();
}

yyerror(char* s) {
	fprintf(stderr, "%s\n", s);
	return 0;
}
