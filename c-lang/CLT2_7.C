#include <stdio.h>
#define D_S 1

#if D_S
#include <conio.h>
#endif
unsigned invert(unsigned, int, int);

unsigned invert(unsigned x, int p, int n){
	unsigned t;

	t = ~(~(unsigned)0 << n) << p - n + 1; /* p - n = x - 1*/
/*#if D_S
	printf("t =0x%04X\n", t);
#endif*/
	return (x ^ t); /* not use (x & ~t) | ((x & t) ^ t)) */
}

#if D_S
int main(){
	clrscr();
	printf("invert(5, 1, 1) =%u\n", invert(5, 1, 1));
	printf("invert(0, 15, 2) =%u\n", invert(0, 15, 2));
	printf("invert(255, 1, 2) =%u\n", invert(255, 1, 2));
	printf("invert(0, 6, 1) =%u\n", invert(0, 6, 1));
	return 0;
}
#endif