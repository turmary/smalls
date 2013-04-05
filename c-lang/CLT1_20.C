/*Programmer:	Tary					*
 *Function:	Fill tab charactor with proper space	*/
#include <stdio.h>
#include <conio.h>
#define D_S 1

#define TABWIDTH 8
#define MAXLINE 2500

#if D_S
FILE* fp_in;
FILE* fp_out;
#else
#define fp_in stdin
#define fp_out stdout
#endif

int detab(char* lsrc, char* ltar);
int getline(char* s);

main(){
	int len;
	char line[MAXLINE], pline[MAXLINE];

	clrscr();
#if D_S
	if(0 == (fp_in = fopen("E:\\vc_file\\cLang\\CLT1_13.C", "r")))
		printf("File For Read Open Error!\n"), exit(0);
	if(0 == (fp_out = fopen("E:\\vc_file\\cLang\\CLT1_20.OUT", "w")))
		printf("File For Write Open Error!\n"), exit(0);
#endif
	while((len = getline(line)) > 0){
		detab(line, pline);
		printf("%s", pline);
		fprintf(fp_out, "%s", pline);
	}
#if D_S
	printf("\n\nWrite File Complete!\n");
	fclose(fp_in);
	fclose(fp_out);
#endif
	return 0;
}

/*process all tab charactor from lsrc to ltar */
int detab(char* lsrc, char* ltar){
	int i, j, n;

	j = 0;
	while(*lsrc){
		switch(*lsrc){
		case '\t':
			n = 8 - j % TABWIDTH;
			for(i = 0; i < n; i++){
				*ltar++ = ' ';
				j++;
			}
			break;
		default:
			*ltar++ = *lsrc;
			j++;
		}
		lsrc++;
	}
	*ltar = '\0';
	return 0;
}

/*read a line and return the length of it*/
int getline(char *s){
	int c, i;

	for(i = 0; (c = fgetc(fp_in)) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}