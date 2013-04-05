#include <stdio.h>

#define D_S_MAIN 1
#define D_S 1

#if D_S
void clrscr(void);
#endif

char* itoa(int);

int si = 0;

int nestItoa(int n, char* s){
	if(n / 10)
		nestItoa(n / 10, s);
	s[si++] = n % 10 + '0';
	return 0;
}

char* itoa(int n){
	static char s[30];

	si = 0;
	if(n < 0){
		s[0] = '-';
		nestItoa(-n, &s[1]);
		s[++si] = 0;
	}else{
		nestItoa(n, s);
		s[si] = 0;
	}
	return s;
}

#if D_S_MAIN
int main(){
	int	type;
	char	s[50];

	clrscr();
	printf("itoa(255) = %s\n", itoa(255));
	printf("itoa(-387) = %s\n", itoa(-387));
	printf("itoa(5323) = %s\n", itoa(5323));
	return 0;
}
#endif