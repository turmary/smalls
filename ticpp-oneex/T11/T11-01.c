//: T11:T11-01.c
//bird & rock

#include <stdio.h>
#include <stdlib.h>

typedef struct bird {
	int b;
}bird;

typedef struct rock {
	int r;
}rock;

int main(void) {
	bird b0;
	rock r0;
	bird* b;
	rock* r;
	void* v;

	b = &b0;
	r = &r0;

	printf("bird = %08x\n", b);
	printf("rock = %08x\n", r);

	v = r;
	b = (bird*)v;

	printf("bird = %08x\n", b);
	printf("rock = %08x\n", r);
	return 0;
} ///:~
