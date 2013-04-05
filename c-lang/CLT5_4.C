#include <stdio.h>
#define D_S_MAIN 1
#define D_S 0

#if D_S
void strclr(void);
#endif

int strend(char*, char*);

int strend(char* s, char* t){
	s = &s[strlen(s) - strlen(t)];
	while(*s++ == *t++)
		;
	if (*t == '\0') return 1;
	else		return 0;
}

#if D_S_MAIN
int main(){
	char a[25] = "Hello World!\n";
	char b[30] = "World\0World!\n";

	clrscr();
	printf("strend(%s , %s) = %d\n", a, b, strend(a, b));
	printf("strend(%s , %s) = %d\n", a, &b[6], strend(a, &b[6]));
	return 0;
}
#endif



