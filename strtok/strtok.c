// tary, 11:10 2012-7-5
#define LBP_DBG
#include <stdio.h>
#include <string.h>
#include "aux_lib.h"

#define LOCAL_DBG	1

#define LINELENGTH 80
#define SEPCHARS " .,?\"\n"

int main(void) {
	char line[LINELENGTH] = "\"My god,\" she said, \" Right?\"";
	char *word;
	int len;

	while(1) {
		if (strlen(line) <= 1) break;
		len = strlen(line);

		printf("line=%s\n", line);
		DBG_BUF("line", line, len);
		DBG_LINE(DNR(1), DVAR(len));
		printf("That line contains these words:\n");
		word = strtok(line, SEPCHARS);
		while (word != NULL) {
			DBG_BUF("line", line, len);
			printf("\"%s\"\n", word);
			word = strtok(NULL, SEPCHARS);
		}
		printf("\nNext line? (empty line to quit)\n");
		fgets(line, LINELENGTH, stdin);
	}
	return 0;
}
