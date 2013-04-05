#include <stdio.h>
#include <ctype.h>
#define D_S_MAIN 1
#define D_S 0

#if D_S
void strclr(void);
#endif

void strcat(char*, char*);

void strcat(char* s, char* t){
	while(*s != '\0')
		s++;
	while(*s++ = *t++)
		;
}

#if D_S_MAIN
int main(){
	char a[25] = "Hello World!\n";
	char b[30] = "Good!";

	clrscr();
	printf("%s + %s = ", a, b);
	strcat(a, b);
	printf("%s\n", a);
	return 0;
}
#endif



