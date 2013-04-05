/*Programmer:	Tary			*
 *Function:	Print the line reverced	*/
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 2500
#define D_S 0
int getline(char* s);
void reverse(char* s, int n);
#if D_S
FILE* fp;
#else
#define fp stdin
#endif

main(){
	int len;
	char line[MAXLINE];

#if D_S
	if(0 == (fp = fopen("E:\\vc_file\\cLang\\CLT1_13.IN", "r")))
		printf("File Open Error!\n"), exit(0);
#endif
	while((len = getline(line)) > 0){
		reverse(line, len);
		printf("%s", line);
	}
#if D_S
	fclose(fp);
#endif
	return 0;
}

/*reverse the string arg1*/
void reverse(char* s, int n){
	int i;
	char t;

	for(i = 0; i < n / 2; i++){
		t = s[i];
		s[i] = s[n - 1 - i];
		s[n - 1 - i] = t;
	}
	return;
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