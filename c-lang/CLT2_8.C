#include <stdio.h>
#define D_S 1

#if D_S
#include <conio.h>
#endif
unsigned rightrot(unsigned, int);

unsigned rightrot(unsigned x, int n){
	return (x >> n) |
	 (
	  (x & ~(~0U << n))  <<
	  sizeof x /*sizeof(unsigned) */* 8 - n
	 );
}

#if D_S
int main(){
	clrscr();
	printf("rightrot(5, 1) =%u\n", rightrot(5, 1));
	printf("rightrot(256, 2) =%u\n", rightrot(256, 2));
	return 0;
}
#endif