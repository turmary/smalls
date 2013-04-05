#include <stdio.h>

#define D_S 0
#define TABINC 8
#define printChars(count, ch) \
for(i = 0; i < count; ++i)putchar(ch)

int main(){
	int c, i, p = 0, n = 0;

	while(EOF != (c = getchar())){
		if(' ' == c){
			++n;
			if(TABINC - 1 == p % TABINC){
#if D_S
				printf("*%d*", n);
#endif
				(n > 0)? putchar((1 == n)? ' ': '\t'): 0;
				n = 0;
			}
		}else{
			if('\t' == c)
				p = (p / TABINC + 1) * TABINC - 1;
			else{
				('\n' == c)? (p = 0): 0;
				printChars(n, ' ');
#if D_S
				printf("%d", n);
#endif
			}
			n = 0, putchar(c);
		}
		++p;
	}
	return 0;
}