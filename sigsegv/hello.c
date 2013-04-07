#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void sig_segv(int);

int main(void) {
	char* s = NULL;

	if (signal(SIGSEGV, sig_segv) == SIG_ERR) {
		perror("install SIGSEGV");
	}

	*s = 0;
	printf("Hello World!\n");
	return 0;
}

static void sig_segv(int signo) {
	fprintf(stderr, "received SIGSEGV\n");
	exit(signo);
}

