#include <stdio.h>
#define D_S 1

#if D_S
#include <conio.h>
#endif
int bitcount(unsigned);

int bitcount(unsigned x){
	int b;

	for(b = 0; x != 0; x &= x - 1)
		b++;
	return b;
}

#if D_S
int main(){
	clrscr();
	printf("bitcount(5) =%u\n", bitcount(5));
	printf("bitcount(127) =%u\n", bitcount(127));
	printf("bitcount(256) =%u\n", bitcount(256));
	return 0;
}
#endif