#include <stdio.h>
#include <string.h>
#define D_S 1

#if D_S
void clrscr(void);
#endif

#define MAXC 255
static char buf[MAXC] = "";

int ungets(char* s){
	if(strlen(s) <= MAXC){
		strcpy(buf, s);
	}else
		printf("error: string to ungets too long\n");
}

char* mgets(char* s){
	if(*buf != '\0'){
		strcpy(s, buf);
		*buf = '\0';
	}else{
		gets(s);
	}
	return s;
}


#if D_S
int main(){
	char s1[50] = "Hello World!", s2[500];

	clrscr();
	ungets(s1);
	mgets(s2);
	printf("s2=%s\n", s2);
	mgets(s2);
	printf("s2=%s\n", s2);
	return 0;
}
#endif