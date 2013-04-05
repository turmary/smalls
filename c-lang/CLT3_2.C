#include <stdio.h>
#define D_S 1

#if D_S
#include <conio.h>
#endif

char* escape(char *, const char *);
char* unescape(char *, const char *);

char* escape(char* s, const char * t){
	char *psrc = t, *ptar = s;

	while(*psrc != '\0'){
		switch(*psrc){
		case '\n':
			*ptar++ = '\\';
			*ptar++ = 'n';
			break;
		case '\t':
			*ptar++ = '\\';
			*ptar++ = 't';
			break;
		default:
			*ptar++ = *psrc;
			break;
		}
		psrc++;
	}
	*ptar = '\0';
	return s;
}

char* unescape(char* s, const char * t){
	char *psrc = t, *ptar = s;

	while(*psrc != '\0'){
		switch(*psrc){
		case '\\':
			switch(*++psrc){
			case 'n':
				*ptar++ = '\n';break;
			case 't':
				*ptar++ = '\t';break;
			}
			break;
		default:
			*ptar++ = *psrc;
			break;
		}
		++psrc;
	}
	*ptar = '\0';
	return s;
}

#if D_S
int main(){
	char	a[] = {"\tHello World\n"},
		b[25];

	clrscr();
	printf("Original=%s\n", a);
	printf("First   =%s\n", escape(b, a));
	printf("Second  =%s\n", unescape(a, b));
	return 0;
}
#endif