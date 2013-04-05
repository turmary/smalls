#include <stdio.h>
#include <limits.h>
#define D_S 1

#if D_S
#include <conio.h>
#endif

void reverse(char s[]);
char* itoa(int, char *, int);

void reverse(char s[]){
	int c, i, j;

	for(i = 0, j = strlen(s)-1; i < j; i++, j--){
		c = s[i]; s[i] = s[j]; s[j] = c;
	}
}


char* itoa(int n, char * s, int w){
	int i, sign = n;

	i = 0;
	do{
		s[i++] = abs(n % 10) + '0';
	}while((n /= 10) != 0);
	if(sign < 0)
		s[i++] = '-';
	for(;i < w; i++)
#if D_S
		s[i] = '\002';
#else
		s[i] = ' ';
#endif
	s[i] = '\0';
	reverse(s);
	return s;
}

#if D_S
int main(){
	int i, a[] = {32767, -32768, 592, -3872, 0, 1, -1};
	char b[125];

	clrscr();
	for(i = 0; i < sizeof(a) / sizeof(int); i++){
		printf("itoa(%6d %2d) \t= %s\n", a[i], 2, itoa(a[i], b, 2));
		printf("itoa(%6d %2d) \t= %s\n", a[i], 10, itoa(a[i], b, 10));
	}
	return 0;
}
#endif