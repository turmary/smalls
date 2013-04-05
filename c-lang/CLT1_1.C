#include <stdio.h>

/*compiler:Turbo C2.0*/

/*if delete e in include, then occur a error:
Unknown preprocessor directive: 'includ'

/*if delete < in function main, then occor a error:
Bad file name format in include directive*/

/*if delete s in stdio, it will give you a error message:
Unable to open include file 'TDIO.H'*/

/*if delete > in include statement, a message will give to you:
No file name ending*/

/*if don't have main(), it will occur a error:
Undefined symbol '_main' in module ...*/

/*if don't have p in printf, it will occur a error:
Undefined symbol 'rintf' in module ...*/

/*if don't have ", it will occur two error:
Unterminated string or character constant in function main
Function call missing ) in function main
or Four error including above two and:
Underfined symbol 'hello' in function main
Underfined symbol 'world' in function main*/

/* if end comment symbol is missing, then appear a error:
Unexpected end of file in comment started on line ...*/

/*if don't have ) after printf or after main or { after main,there is a error:
Declaration syntax error*/

/*if delete ( before hello,then appear three error:
Undefined symbol 'printf' in function main
Code has  no effect in function main
Statement missing ; in function main*/

/*if delete ; before }, then appear a error:
Statement missing ; in function main*/

/*if delete } in the end of file, then appear:
Compound statement missing } in function main*/

main(){
	printf("hello, world!");
}