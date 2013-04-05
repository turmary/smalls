#include <stdio.h>
#define IN 1
#define OUT 0

main(){
	int c, nl, nw, nc, state, i;
	char word[35];

	state = OUT;
	i = nl = nw = nc = 0;
	while((c = getchar()) != EOF){
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n'
		 || c == '\t' || c == ','
		 || c == '.' || c == '\''){
			state = OUT;
			word[i++] = '\0';
			printf("%s", word);
			i = 0;
		}else if(state == OUT){
			state = IN;
			++nw;
			printf("\n");
		}
		if(state == IN)
			word[i++] = c;
	}
	printf("Line=%d\tWord=%d\tChar=%d\n", nl, nw, nc);
}