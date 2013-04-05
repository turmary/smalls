#include <stdio.h>
#define D_S 1

#if D_S
#include <conio.h>
#endif
unsigned setbits(unsigned, int, int, unsigned);

unsigned setbits(unsigned x, int p, int n, unsigned y){
	unsigned t;

	t = ~(~(~0U << n) << p - n + 1); /* p - n = x - 1*/
	y = (y & ~(~0U << n)) << p - n + 1;
/*#if D_S
	printf("t =0x%04X y =0x%04X \n", t, y);
#endif*/
	return y | (x & t);
}

#if D_S
int main(){
	clrscr();
	printf("setbits(5, 1, 2, 3) =%u\n", setbits(5, 1, 2, 3));
	printf("setbits(0, 15, 1, 1) =%u\n", setbits(0, 15, 1, 1));
	printf("setbits(0, 7, 8, 127) =%u\n", setbits(0, 7, 8, 127));
	printf("setbits(0, 6, 2, 3) =%u\n", setbits(0, 6, 2, 3));
	return 0;
}
#endif