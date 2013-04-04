#include <stdio.h>

char format[]= "%s,%s %s\n";
char hello[] = "hello";
char world[] = "world";
char tary[]  = "tary";

int main(int argc, char* argv[]) {
	_asm
	{
		mov	eax, offset world
		push	eax
		mov	eax, offset hello
		push	eax
		mov	eax, offset tary
		push	eax
		mov	eax, offset format
		push	eax
		call	printf
		//clean up the stack so that main can exit cleanly
		//use the unused register ebx to do the cleanup
		pop	ebx
		pop	ebx
		pop	ebx
		pop	ebx
	}
}
