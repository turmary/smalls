#include <stdio.h>

#define D_S_MAIN 1
#if D_S_MAIN
void clrscr(void);
#endif

#define BUFSIZE 100

int buf[BUFSIZE], bufp = 0;

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if(bufp >= BUFSIZE)
		printf("ungetch: too many charactors\n");
	else
		buf[bufp++] = c;
}

#if D_S_MAIN
int main(){
	int i = 0;

	clrscr();
	ungetch('H');
	ungetch('o');
	for(;i < 10; i++)
		printf("%d\n", getch());
	return 0;
}
#endif