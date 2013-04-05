#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fcmp(const void *a, const void *b);

char list[5][10] = {"hello", "tary", "name", "is", "my" };


int main(void)
{
	int  x;

	qsort((void *)list, 5, sizeof(list[0]), fcmp);
	for (x = 0; x < 5; x++)
		printf("%s\n", list[x]);
	return 0;
}

int fcmp( const void *a, const void *b)
{
	return( strcmp(a,b) );
}
