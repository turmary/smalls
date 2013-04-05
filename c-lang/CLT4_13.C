#include <stdio.h>
#define D_S_MAIN	1
#define D_S		1

#if D_S
void clrscr(void);
#endif

void __reverse__ (char* s, int i, int j){
	char t;

	if(i < j){
		t = s[i];
		s[i] = s[j];
		s[j] = t;
		__reverse__ (s, i + 1, j - 1);
	}
}

/*reverse the string s, n is the length of s */
char* reverse(char* s, int n){
	__reverse__ (s, 0, n - 1);
	return s;
}

#if D_S_MAIN
int main(){
	char *p = "Hello World!", *q;

	clrscr();
	gets(q);
	printf("p = %s\n", p);
	printf("reverse(p) = %s\n", reverse(p, strlen(p)));
	printf("q = %s\n", q);
	printf("reverse(q) = %s\n", reverse(q, strlen(q)));
	return  0;
}
#endif