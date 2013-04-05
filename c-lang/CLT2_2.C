#include <stdio.h>

#define D_S 1
#if D_S
#include <conio.h>
#endif

int main(){
	int i, c, lim = 386;
	char s[5000] = {0};
#if D_S
	clrscr();
#endif
	/*for(i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;						*/
	for(i = 0; i < lim - 1; ++i){
		if((c = getchar()) == '\n')
			break;
		else if(c == EOF)
			break;
		s[i] = c;
	}
	printf("\n%s", s);
}