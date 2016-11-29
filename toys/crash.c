#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char ch, *p = &ch;

	for ( ; 1; p--)
		*p = '\0';
	return EXIT_SUCCESS;
}

