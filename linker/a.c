#include <stdio.h>

char *p = "abcdefgh";

int f();

int main() {

	printf("&p = %.8X\n", &p);
	printf("*p = %c\n", *p);
	printf("p = %.8X\n", p);
	printf("p = %s\n", p);

        {
        int i;

        for (i = 0; i < 4; i++) {
                printf("p[%d] = 0x%.2X\n", i, p[i]);
        }
	}

	f();

	return 0;
}

