#include <stdio.h>

main(){
	int space, tab, newline;
	signed char c;  /* the signed symbol is important,
			if miss it, the program will not end forever*/

	space = tab = newline = 0;
	while((c = getchar()) != EOF){
		if(c == '\n')
			++newline;
		else if(c == '\t')
			++tab;
		else if(c == ' ')
			++space;
	}
	printf("space=%d\ntab=%d\nnewline=%d\n", space, tab, newline);
}