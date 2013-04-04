#include <stdio.h>
#include <stdlib.h>
#include "hello_so.h"

int main(int argc, char* argv[]) {
	int x, y;

	if (argc < 3) {
		fprintf(stderr, "%s x y\n", argv[0]);
		return 0;
	}

	x = atoi(argv[1]);
	y = atoi(argv[2]);

	printf(" %d * %d = %d\n", x, y, hello_so(x, y));

	return 0;
}
