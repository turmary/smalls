#include <stdio.h>
#include <string.h>
#define D_S 1

#if D_S
#include <conio.h>
#endif

int strindex(char * s, char * t);

int strindex(char * s, char * t){
	int i, j, k;

	for(i = strlen(s)-strlen(t)+1; i >= 0; i--){
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if(k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

#if D_S
int main(){
	char i, a[][6] = {"", "then", "and", ";", "Would", " ", "h"};
	char b[125] = "Would not we shatter it to bits -then- and then;";

	clrscr();
	for(i = 0; i < sizeof(a) / sizeof(char [6]); i++){
		printf("strindex(%s, %s)\t= %d\n", b, a[i], strindex(b, a[i]));
	}
	return 0;
}
#endif