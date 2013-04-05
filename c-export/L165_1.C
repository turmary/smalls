#include <signal.h>

#include <stdio.h>



void handler(int s){

	if(s == SIGBUS)

		printf("bus error\n");

	else if(s == SIGSEGV)

		printf("segmentation violation\n");

	else if(s == SIGILL)

		printf("illegal instruction signal\n");

	else

		exit(1);

}



main(){

	int *p = NULL;

	signal(SIGBUS, handler);

	signal(SIGSEGV, handler);

	signal(SIGILL, handler);

	*p = 0;

}

