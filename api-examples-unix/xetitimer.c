// tary, 10:54 2013-1-30
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/time.h>

static int limit = 50;

/* signal process */
void timeout_info(int signo)
{
	if (limit == 0)
	{
		printf("Sorry, time limit reached.\n");
		exit(0);
		return;
	}
	printf("only %d seconds left.\n", limit--);
}

/* init sigaction */
void init_sigaction(void)
{
	struct sigaction act;

	act.sa_handler = timeout_info;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGALRM, &act, NULL);
}

/* init */
void init_time(void)
{
	struct itimerval val;

	val.it_value.tv_sec = 0;
	val.it_value.tv_usec = 20;
	val.it_interval = val.it_value;
	setitimer(ITIMER_REAL, &val, NULL);
}

int main(void)
{
	init_sigaction();
	init_time();
	printf("You have only 10 seconds for thinking.\n");

	while (1);
	return 0;
}
