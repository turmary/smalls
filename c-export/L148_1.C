
#include <stdio.h>
#include <stdlib.h>

main(){
	int KB = 0;

	while(malloc(1 << 10)) ++KB;
	printf("Allocated %d KB total\n", KB);
}