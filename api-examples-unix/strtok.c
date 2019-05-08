#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	char s[] = "ab-cd: ef;gh: i-jkl;mnop;qrs-tu: vwx-y;z";
	char* delim = "-: ";
	char* p;
	char s2[] = "D  \t5 52 53 54";
	char* n;

	printf("%s \n", strtok(s, delim));
	while ((p = strtok(NULL, delim))) printf("%s \n", p);
	printf("\n");

	p = s2 + 1;
	while ((n = strsep(&p, " \t")) != NULL) {
		printf("strsep = %s\n", n);
	}
	return 0;
}
