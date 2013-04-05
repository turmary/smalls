#include <stdio.h>
#include <limits.h>

#define D_S 1
#if D_S
#include <conio.h>
#endif

int main(){
#if D_S
	clrscr();
#endif
	printf("MAX SIGNED CHAR =%d SHORT =%d INT =%d LONG =%ld\n",
	  SCHAR_MAX, SHRT_MAX, INT_MAX, LONG_MAX);
	printf("MIN SIGNED CHAR =%d SHORT =%d INT =%d LONG =%ld\n",
	  SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
	printf("MAX UNSIGNED CHAR =%u SHORT =%u INT =%u LONG =%lu\n",
	  UCHAR_MAX, USHRT_MAX, UINT_MAX, ULONG_MAX);
	printf("MIN UNSIGNED CHAR =%d SHORT =%u INT =%u LONG =%lu\n",
	  0, 0, 0, (unsigned long)0);
	printf("CHAR MAX =%d MIN =%d\n",/*the result consponse to the char is signed or unsigned*/
	   CHAR_MAX, CHAR_MIN);
}