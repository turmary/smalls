#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define D_S 1

#if D_S
#include <conio.h>
#endif
void squeeze(char*, char*);

void squeeze(char s1[], char s2[]){
	int i, j;

	for(i = j = 0; s1[i] != '\0'; i++)
		if(strchr(s2, s1[i])  == NULL)
			s1[j++] = s1[i];
	s1[j] = '\0';
}

#if D_S
int main(){
	char a[50] = "0x5f3hello world my name is tary.....";
	char b[50] = "hfoi0.";

	clrscr();
	printf("a =%s b =%s\n", a, b);
	squeeze(a, b);
	printf("After squeeze(a, b) a =%s\n", a);
	return 0;
}
#endif