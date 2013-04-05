/*Programmer:	Tary					*
 *Function:	Print the longest line of inputed	*/
#include <stdio.h>
#define MAXLINE 214748

int getline(char line[]);
void copy(char to[], char from[]);

main(){
	int len;
	int max;
	char line[MAXLINE], longest[MAXLINE];

	max = 0;
	while((len = getline(line)) > 0)
		if(len > max){
			max = len;
			copy(longest, line);
		}
	if(max > 0)
		printf("%s\n", &longest[0]);
	printf("Line Length:%d", max);
	return 0;
}

/*read a line and return the length of it*/
int getline(char s[]){
	int c, i;

	for(i = 0; (c = fgetc(stdin)) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/*copy string from array arg2 to array arg1*/
void copy(char to[], char from[]){
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}