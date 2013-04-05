/*Programmer:	Tary				*
 *Function:	Print the word length table	*/
#include <stdio.h>
#define IN 1
#define OUT 0

void main (){
	int i, j, row, t = 0;
	int wordlen[50]={0};
	int c, state, max;

	clrscr();
	state = OUT;
	i = 0;
	while((c = getchar()) != EOF){
		if(c == ' ' || c == '\n'
		 || c == '\t' || c == ','
		 || c == '.' || c == '\''){
			if(state == IN)
				wordlen[i]++;
			state = OUT;
		}else if(state == OUT){
			state = IN;
			i = 1;
		}else
			i++;
	}

	for(i = 49; !wordlen[i]; i--);
	max = i + 1;

	for(i = 1; i < max; i++)
		if(t < wordlen[i])
			t = wordlen[i];
	row = t;
	for(i = 0; i < row ;i++){
		for(j = 1;j < max;j++)
			if(wordlen[j] >= t)
				printf("  *");
			else
				printf("   ");
		printf("\n"),t--;
	}

	for(i = 1; i < max; i++)
		printf("%3d", wordlen[i]);
	printf("\n");
	for(i = 1; i < max; i++)
		printf("%3d", i);
	printf("\n");
}