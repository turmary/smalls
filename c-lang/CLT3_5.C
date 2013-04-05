#include <stdio.h>
#include <string.h>
#include <limits.h>
#define D_S 1

#if D_S
#include <conio.h>
#endif

void reverse(char s[]);
char* itob(int, char*, int);

void reverse(char s[]){
	int c, i, j;

	for(i = 0, j = strlen(s)-1; i < j; i++, j--){
		c = s[i]; s[i] = s[j]; s[j] = c;
	}
}


char* itob(int n, char* s, int b){
	int i = 0, sign = 0;
	long int nt = n;

	if(n < 0){
		sign = -1;
		nt = -(long)n;
	}
	do{
		int it = nt % b;
		s[i++] = (it < 10)
			? (it + '0')
			: it + 'A' - 10;
	}while((nt /= b) > 0);
	if(sign)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
	return s;
}

#if D_S
int main(){
	int i, a[] = {32767, -32768, 592, -3872};
	char b[125];

	clrscr();
	for(i = 0; i < sizeof(a) / sizeof(int); i++){
		printf("itob(%6d, %3d) \t= %s\n", a[i], 2, itob(a[i], b, 2));
		printf("itob(%6d, %3d) \t= %s\n", a[i], 8, itob(a[i], b, 8));
		printf("itob(%6d, %3d) \t= %s\n", a[i], 16, itob(a[i], b, 16));
	}
	return 0;
}
#endif