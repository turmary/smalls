#include <stdio.h>
#define D_S_MAIN	1
#define D_S		1
#define swap(t, x, y) {t vt; vt = x; x = y; y = vt;}
#if D_S
void clrscr(void);
#endif

#if D_S_MAIN
int main(){
	char *p = "Hello World!";
	int a = 25, b = 38;

	clrscr();
	printf("p = %s\n", p);
	swap(char, p[0], p[1]);
	printf("after swap p[0] and p[1], p = %s\n", p);
	printf("a = %d b = %d\n", a, b);
	swap(int, a, b);
	printf("after swap a and b, a = %d b = %d\n", a, b);
	return  0;
}
#endif