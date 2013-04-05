#include <stdio.h>

#define D_S_MAIN 1
#if D_S_MAIN
void clrscr(void);
#endif

#define BUFSIZE 100

unsigned char buf[1] = "";

int getch(void){
	char c;

	c = (*buf > 0) ? *buf : getchar();
	*buf = '\0';
	return c;
}

void ungetch(int c){
	if(*buf > 0)
		printf("ungetch: too many charactors\n");
	else
		buf[0] = c;
}

#if D_S_MAIN
int main(){
	int i = 0;

	clrscr();
	ungetch('H');
	ungetch('o');
	for(;i < 10; i++)
		printf("%c\n", getch());
	return 0;
}
#endif