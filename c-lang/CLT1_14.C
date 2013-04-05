/*Programmer:	Tary				*
 *Function:	Print the chars length table	*/
#include <stdio.h>
#define BEGIN 33
#define END 128

void main (){
	int i, j, row, t = 0;
	int wordlen[256]={0};
	int c;

	clrscr();
	while((c = fgetc(stdin)) != EOF)
		wordlen[c]++;

	for(i = BEGIN; i < END; i++)
		if(t < wordlen[i])
			t = wordlen[i];
	row = t;
	for(i = 0; i < row ;i++){
		for(j = BEGIN; j < END;j++)
			if(wordlen[j] >= t)
				printf("*");
			else if(wordlen[j])
				printf(" ");
		printf("\n"),t--;
	}

	for(i = BEGIN; i < END; i++)
	if(wordlen[i])
		printf("%c", i);
	printf("\n");

	for(i = BEGIN; i < END; i++)
	if(wordlen[i])
		printf("%c(%3d):%3d\n", i, i, wordlen[i]);
}