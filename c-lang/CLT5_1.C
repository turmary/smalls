#include <stdio.h>
#include <ctype.h>
#define D_S_MAIN 1
#define D_S 1

#if D_S
void clrscr(void);
#endif


#define getch() getchar()
void ungetch(char);

int getint(int *pn){
	int nc, c, sign;

	while(isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-'){
		nc = c, c = getch();
		if(!isdigit(c)){
			ungetch(nc);
			return -1;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#if D_S_MAIN
int main(){
	int i;
	int a;

#if D_S
	clrscr();
#endif
	i = getint(&a);
	printf("getint(&a) = %d a = %d\n", i, a);
	i = getint(&a);
	printf("getint(&a) = %d a = %d\n", i, a);
	i = getint(&a);
	printf("getint(&a) = %d a = %d\n", i, a);
	return 0;
}
#endif