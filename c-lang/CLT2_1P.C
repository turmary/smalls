#include <stdio.h>
#include <limits.h>

#define D_S 0
#if D_S
#include <conio.h>
#endif

int main(){
#if D_S
	clrscr();
#endif
	printf("MAX SIGNED CHAR =%d SHORT =%d INT =%d LONG =%ld\n",
	  (signed char) (~(unsigned char)0 >> 1),
	  (short) (~(unsigned short)0 >> 1),
	  (int) (~(unsigned int)0 >> 1),
	  (long) (~(unsigned long)0 >> 1));
	printf("MIN SIGNED CHAR =%d SHORT =%d INT =%d LONG =%ld\n",
	  (signed char) ((~(unsigned char)0 >> 1) + 1),
	  (short) ((~(unsigned short)0 >> 1) + 1),
	  (int) ((~(unsigned int)0 >> 1) + 1),
	  (long) ((~(unsigned long)0 >> 1) + 1));
	printf("MAX UNSIGNED CHAR =%u SHORT =%u INT =%u LONG =%lu\n",
	  ~(unsigned char)0, ~(unsigned short)0,
	  ~(unsigned int)0, ~(unsigned long)0);
	printf("MIN UNSIGNED CHAR =%u SHORT =%u INT =%u LONG =%lu\n",
	  0, 0, 0, 0UL);
}