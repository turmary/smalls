#include <stdio.h>
#include <conio.h>
#define D_S_MAIN 1
#define D_S 1

#if D_S
void strclr(void);
#endif

char* strncpy(char* s, char* t, int n){
	int i = 0;
	while (i < n && t[i]){
		s[i] = t[i++];
	}
	s[i] = '\0';
	return s;
}

char* strncat(char* s, char* t, int n) {
	char *sp = s;
	while (*sp) sp++;
	for (; (n-- > 0) && *t;)
		*sp++ = *t++;
	*sp = '\0';
	return s;
}

int strncmp(char* s, char* t, int n) {
	int i = 0;
	while (++i < n) {
		if (*s != *t)	break;
		else { s++; t++; }
	}
	return *s - *t;
}

#if D_S_MAIN
int main(){
	int n = 7, i;
	char a[25] = "A";
	char b[30] = "Hello\0Morning!\n";

	clrscr();
	for (i = 1; i < n; i++){
		printf("Time %d\\\\\\\\\\\n", i);
		printf("strncpy(%s , %s, %d) = %s\n", a, b, i, strncpy(a, b, i));
		printf("strncat(%s , %s, %d) = %s\n", a, &b[6], i, strncat(a, &b[6], i));
		printf("strncmp(%s , %s, %d) = %d\n", a, b, i, strncmp(a, b, i));
	}
	return 0;
}
#endif
