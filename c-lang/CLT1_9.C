#include <stdio.h>
#define IN 1
#define OUT 0

main(){
	int c, state;

	state = OUT;
	c = getchar();
	while(c != EOF){
		if(state == OUT){
			putchar(c);
		}
		if(c == ' ')
			state = IN;
		else if(state == IN)
			state = OUT;
		c = getchar();
	}
}