#include <stdio.h>

extern unsigned char p[];

int f(void) {
	printf("%s()\n", __func__);
        printf("&p = %.8X\n", &p);
        printf("p = %.8X\n", p);
        printf("p = %s\n", p);
	{
	int i;

	for (i = 0; i < 4; i++) {
		printf("p[%d] = 0x%.2X\n", i, p[i]);
	}
	}

	return 0;
}

