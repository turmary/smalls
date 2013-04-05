#include <stdio.h>
#include <limits.h>
#define D_S 1

#if D_S
#include <conio.h>
#endif

void reverse(char s[]);
char* itoa(int, char *);

void reverse(char s[]){
	int c, i, j;

	for(i = 0, j = strlen(s)-1; i < j; i++, j--){
		c = s[i]; s[i] = s[j]; s[j] = c;
	}
}


char* itoa(int n, char * s){
	int i, sign, signMin = 0;

	if((sign = n) < 0)
		if(n != INT_MIN)
			n = -n;
		else{
			signMin = 1;
			n = - (n + 1);
		}
	i = 0;
	do{
		s[i++] = n % 10 + '0';
	}while((n /= 10) > 0);
	if(sign < 0)
		s[i++] = '-';
	if(signMin)
		s[0]++;
	s[i] = '\0';
	reverse(s);
	return s;
}

#if D_S
int main(){
	int i, a[] = {32767, -32768, 592, -3872};
	char b[125];

	clrscr();
	for(i = 0; i < sizeof(a) / sizeof(int); i++)
		printf("itoa(%d) \t= %s\n", a[i], itoa(a[i], b));
	return 0;
}
#endif