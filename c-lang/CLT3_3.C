#include <stdio.h>
#define D_S 1

#if D_S
#include <conio.h>
#endif

char* expand(char const * const, char *);

char* expand(char const * const s1, char * s2){
	static char oc = '\0';
	char *psrc = s1, *ptar = s2;

	while(*psrc != '\0'){
		switch(*psrc){
		case '-':
			if(oc && oc < psrc[1]){
				++psrc;
				while(*psrc > oc)
					*ptar++ = ++oc;
			}else
				*ptar++ = *psrc;
			break;
		default:
			*ptar++ = *psrc;
			break;
		}
		oc = *psrc++;
	}
	*ptar = '\0';
	return s2;
}

#if D_S
int main(){
	char	a[] = {"-a-g-pGoodhp-aHello-zWorld0-5W-Z-----"},
		b[125];

	clrscr();
	printf("Original=%s\n", a);
	printf("First   =%s\n", expand(a, b));
	return 0;
}
#endif