#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define D_S 0

#if D_S
#include <conio.h>
#endif
int hexDigit(int);

int hexDigit(int c){
	if(isdigit(c))
		return 1;
	else if('A' <= c && c <= 'F')
		return 2;
	else if('a' <= c && c <= 'f')
		return 3;
	else
		return 0;
}

int htoi(char* s){
	int i = 0, c, t = 0;

	if(!strncmp("0x", s, 2) || !strncmp("0X", s, 2))
		i = 2;
	while(c = hexDigit(s[i])){
		switch(c){
		case 1:
			t = 16 * t + s[i] - '0';
			break;
		case 2:
			t = 16 * t + s[i] - 'A' + 10;
			break;
		case 3:
			t = 16 * t + s[i] - 'a' + 10;
			break;
		default:
			printf("Error when convert\n");
		}
		i++;
#if D_S
		/*printf("%d\t", i);     */
#endif
	}
	return t;
}

#if D_S
int main(){
	char a[50] = "0x5f3z";
	char b[50] = "0X5f3";
	char c[50] = "5f3w";

	printf("%s = %d %d %d \n", a, htoi(a), htoi(b), htoi(c));
	return 0;
}
#endif