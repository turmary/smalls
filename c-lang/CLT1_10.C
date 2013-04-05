#include <stdio.h>
#define TAB '\t'
#define BACKSPACE '\b'
#define DECLINE '\\'

main(){
	int c;

	c = getchar();
	while(c != EOF){
		if(c == TAB)
			printf("%s", "\\t");
		else if(c == BACKSPACE)
			printf("%s", "\\b");
		else if(c == DECLINE)
			printf("%s", "\\\\");
		else
			putchar(c);
		c = getchar();
	}
}