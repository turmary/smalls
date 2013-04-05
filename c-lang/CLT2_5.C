#include <stdio.h>
#include <string.h>
#define D_S 1

#if D_S
#include <conio.h>
#endif
int any(char*, char*);

int any(char s1[], char s2[]){
	int i, j;

	for(i = j = 0; s1[i] != '\0'; i++)
		if(strchr(s2, s1[i])  != NULL)
			return i;
	s1[j] = '\0';
}

#if D_S
int main(){
	char a[50] = "0x5f3hello world my name is tary.....";
	char b[50] = "hoi.";

	clrscr();
	printf("a =%s b =%s\n", a, b);
	printf("Apear position(a, b) a =%d\n", any(a, b));
	return 0;
}
#endif