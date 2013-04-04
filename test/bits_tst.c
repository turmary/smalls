#include <stdio.h>
#include <stdlib.h>

/**
 * ffs - find first bit set
 * @x: the word to search
 *
 * This is defined the same way as
 * the libc and compiler builtin ffs routines, therefore
 * differs in spirit from the above ffz (man ffs).
 */
static inline int ffs(int x) {
	int r = 0;

	if (!x)	return 0;

	if (!(x & 0xffff)) {
		x >>= 16; r += 16;
	}
	if (!(x & 0xff)) {
		x >>= 8; r += 8;
	}
	if (!(x & 0xf)) {
		x >>= 4; r += 4;
	}
	if (!(x & 3)) {
		x >>= 2; r += 2;
	}
	if (!(x & 1)) {
		x >>= 1; r += 1;
	}
	return r;
}

#define _NSIG_BPW 32
#define ffz(x)	ffs(~(x))

int main() {
	unsigned long s[] = {0x1234, 0x0004};
	unsigned long m[] = {0xFF00, 0xFF00};
	unsigned long x;
	int sig;
	
	if (((x = s[0]) & ~m[0]) != 0)
		sig = 1;
	else if (((x = s[1]) & ~m[1]) != 0)
		sig = _NSIG_BPW + 1;
	sig += ffz(~x);

	printf("x = %.8X\n", x);
	printf("~x = %.8X\n", ~x);
	printf("sig = %d\n", sig);

	return 0;
}
