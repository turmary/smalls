#include <stdio.h>
#include <math.h>
#include <string.h>

#define D_S 0         /* debug {sign }}'he[re \' good*/
void powQuote(int);   /* print all cha[rs between two] Quotes "  "*"/"\" */
void powRem();        /* process all Rem(comment )in programs */
int signIndex(char);
enum Signs{ l_small, l_medium, l_big, r_big, r_medium, r_small};
struct Counter{
	int Total[6];
	int Line[6][100];
}Count = {{0}, {{0}}};
int apl = 1;	/* appear line number */

int signIndex(char c){
	static const char* scp = "([{}])";
	char* sp;

	sp = strchr(scp, c);
	if(sp)
		return (sp - (char *)scp);
	else
		return -1;
}

int main(){
	int c, lc, si;
	char* String = "([{}])Hell' /' \")/*o Wo*/(r\' '\"/*ld*/\n";

	lc = '\n';
	while(EOF != lc){
		c = getchar();
		if('/' == lc && '*' == c){
			powRem();
			c = getchar();
		}else if(('\'' == c || '\"' == c) && lc != '\\'){
			powQuote(c);
			c = getchar();
		}else if(0 <= (si = signIndex(c)))
			if(si < 3 || 0 == Count.Total[5 - si])
				Count.Line[si][Count.Total[si]++] = apl;
			else   /* appear }]) */
#if D_S
			if(Count.Total[5 - si] > 0)
#endif
				Count.Line[5 - si][Count.Total[5 - si]--] = apl;
		else if('\n' == c)
			apl++;
		lc = c;
	}
	for(lc = 0; lc < 6; lc++){
		printf("\nMissing %c", String[lc]);
		for(c = 0; c < Count.Total[lc]; c++)
			printf("\n\tline %d", Count.Line[lc][c]);
		if(0 == Count.Total[lc])
			printf("\nNo missing");
	}
	return 0;
}

void powQuote(int bc){
	int c, lc = bc;

	while(EOF != lc){
		c = getchar();
		if(c == bc && lc != '\\')
			return;
		else if('\n' == c)
			apl++;
		lc = c;
	}
}

void powRem(int lc){
	int c;

	while(EOF != lc){
		c = getchar();
		if('*' == lc && '/' == c)
			return;
		else if('\n' == c)
			apl++;
		lc = c;
	}
}
