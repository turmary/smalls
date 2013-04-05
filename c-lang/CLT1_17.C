/*Programmer:	Tary						*
 *Function:	Print the line which length large than 80	*/
#include <stdio.h>
#define MAXLINE 214748

int getline(char line[]);

main(){
	int len;
	char line[MAXLINE];

	while((len = getline(line)) > 0)
		if(len > 80)
			printf("Len=%d:\n%s\n", len, line);
	return 0;
}

/*read a line and return the length of it*/
int getline(char *s){
	int c, i;

	for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}