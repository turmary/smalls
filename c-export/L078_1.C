#include <stdio.h>

#define STRCMP(a, R, b) (strcmp(a, b) R 0)

main(){
	char *s = "hello world!";
	char *t = "hello world!";
	printf("(%s == %s) = %d", s, t, STRCMP(s, == , t));
	return 0;
}