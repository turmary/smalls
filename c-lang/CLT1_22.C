#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define D_S 0
#define TABINC 8
signed char* buf;
int usage();
int mgetch();
void mungetch(int c);
int flSpace(char *);
int getline(char *, int);

int main(int argc, char* argv[]){
	int len, i = 0, n = 20;

	if(argc > 2 || argc == 2 && argv[1][0] != '-'){
		usage();
		exit(1);
	}else if(argc == 2)
		n = atoi(&argv[1][1]);
#if D_S
	printf("n = %d", n);
#endif
	buf = malloc(n+1);
	while((len = getline(buf, n)) > 0){
		if(buf[len-1] == '\n')
			printf("%s", buf);
		else{
			i = flSpace(buf);
			printf("%s\n", buf);
			while(buf[i] && i < n){
				mungetch(buf[i++]);
	#if D_S
				printf("ungetch %d %d\n", i, buf[i-1]);
	#endif
			}
		}
	}
	return n;
}

int getline(char* s, int n){
	int c, l, p = 0;

	for(l = 0;
	  (p < n - 1) && (c = mgetch()) != EOF &&
	  26 != c && ('\n' != c); ++l){
		s[l] = c;
		if('\t' == c)
			p = (p / TABINC + 1) * TABINC;
		else
			p++;
	}
	if(p >= n - 1)
		l--, mungetch(c);
        else if('\n' == c)
                s[l++] = '\n';
	s[l] = '\0';
	return l;
}

/* find the last none-space character
 and add \0 to it's end
 return index (of \0) + 1*/
int flSpace(char s[]){
	int i = strlen(s), l = i;

	s[i+1] = s[i];
	for(; i > 0; --i){
		s[i] = s[i-1];
		if(' ' != s[i] && '\t' != s[i] && 26 != s[i])
			break;
	}
	i? (s[i] = '\0'): (i = l);
	return i + 1;
}

int usage(){
	printf("Authorised by tary (2005-8-10)\n");
	printf("Usage: CLT1_22 -n\n");
	printf(" CLT1_22: this executable program's name\n");
	printf(" n	: optional(20), a number to ask how\n much row to devide\n");
	return 0;
}

#define BUFSIZE 1024

signed char BUF[BUFSIZE];
int bufp = 0;

int mgetch(void){
	return (bufp > 0)? BUF[--bufp]: getchar();
}

void mungetch(int c){
	if(bufp >= BUFSIZE)
		printf("mungetch: too many characters\n");
	else
		BUF[bufp++] = c;
}
