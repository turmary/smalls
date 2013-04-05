/* CWAIT.C: This program launches several processes and waits
 * for a specified process to finish.
 */

#include <windows.h>
#include <process.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Macro to get a random integer within a specified range */
#define getrandom( min, max ) (( rand() % (int)((( max ) + 1 ) - ( min ))) + ( min ))

struct PROCESS {

	int nPid;
	char name[40];

} process[4] = { {
0, "Ann"}, {
0, "Beth"}, {
0, "Carl"}, {
0, "Dave"}};

void main(int argc, char *argv[])
{
	int termstat, c;

	srand((unsigned) time(NULL));	/* Seed randomizer */
	/* If no arguments, this is the calling process */
	if (argc == 1) {
		/* Spawn processes in numeric order */
		for (c = 0; c < 4; c++) {
			_flushall();
			process[c].nPid = spawnl(_P_NOWAIT, argv[0], argv[0], process[c].name, NULL);
		}

		/* Wait for randomly specified process, and respond when done */
		c = getrandom(0, 3);
		printf("Come here, %s.\n", process[c].name);
		_cwait(&termstat, process[c].nPid, _WAIT_CHILD);
		printf("Thank you, %s.\n", process[c].name);
	}
	/* If there are arguments, this must be a spawned process */
	else {
		/* Delay for a period determined by process number */
		Sleep((argv[1][0] - 'A' + 1) * 1000L);
		printf("Hi, Dad. It's %s.\n", argv[1]);
	}
}
