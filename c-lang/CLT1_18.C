/*Programmer:	Tary							*
 *Function:	Print the line which end with empty,tab or space	*/
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 2500
#define D_S 0

int getline(char line[]);
#if D_S
FILE* fp;
#else
#define fp stdin
#endif

main(){
	int i, len;
	char line[MAXLINE];

#if D_S
	if(!(fp = fopen("E:\\usbtemp\\note\\experence.txt", "r")))
		printf("File Open Error!\n"), exit(0);
#endif
	while((len = getline(line)) > 0){
		for(i = len - 1; (line[i] == '\n'
		 || line[i] == ' '
		 || line[i] == '\t') && i >= 0;)i--;
		line[i + 1] = '\n';
		line[i + 2] = '\0';
		if(i >= 0)
			printf("%s", line);
	}
#if D_S
	fclose(fp);
#endif
	return 0;
}

/*read a line and return the length of it*/
int getline(char *s){
	int c, i;

	for(i = 0; (c = fgetc(fp)) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}