#include <stdio.h>
#define D_S 1

#if D_S
#include <conio.h>
#endif

int lower(int c){

	('A' <= c && c <= 'Z')? c += 'a' - 'A': 0;
	return c;
}

#if D_S
int main(){
	clrscr();
	printf("lower('A')=%c\n", lower('A'));
	printf("lower('&')=%c\n", lower('&'));
	printf("lower('w')=%c\n", lower('w'));
	return 0;
}
#endif