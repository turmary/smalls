#define NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAXLINE 512
#define OPCODE_NUM 52

int divtoken(char linet[]);
int getline(char line[]);
void copy(char to[], char from[]);
int line2upper(char line[], int n);
int addblank(char *line);
int getsign(char linet[], char cpos[], char sign[]);
char* opocur(char linet[], char opcode[]);
int getopcode(char si[], char comment[], char oppart[]);


char *OpCodes[OPCODE_NUM] = {
	"NOP", "MOVX", "MOVC", "MOV",
	"PUSH", "POP", "XCHD", "XCH",
	"SWAP", "ADDC", "DJNZ", "ADD",
	"SUBB", "INC", "DEC", "MUL",
	"DIV", "DA", "ANL", "ORL",
	"XRL", "CLR", "CPL", "RL",
	"RLC", "RR", "RRC", "SETB",
	"ACALL", "LCALL", "RETI", "RET",
	"AJMP", "LJMP", "SJMP", "JZ",
	"JNZ", "JC", "JNC", "JBC",
	"JNB", "JB", "CJNE", "JMP",

	"DATA", "BIT", "EQU", "DS",
	"DB", "DW", "END", "ORG"
};


main(){
	int len;
	char line[MAXLINE], linet[MAXLINE], *reline;

	printf("%s\n", ";indented by indent51(written by Tary 2006-05-17)");
	do {
		len = getline(line);
		line2upper(line, len);
		copy(linet, line);
		if(divtoken(linet))
			printf("%s\n", linet);
		else
			printf("%s\n", line);
	} while(len >= 0);
	return 0;
}

int line2upper(char line[], int n){
	int i;

	for (i = 0; i < n && !(line[i] == ';' || line[i] == '\n'); ++i)
		line[i] = toupper(line[i]);
	return 1;
}


char* opocur(char linet[], char opcode[]) {
	int i, j, ocur = 0;
	char* cp;

	for(i = 0; i < OPCODE_NUM; ++i){
		j = strlen(OpCodes[i]);
		if(NULL != (cp = strstr(linet, OpCodes[i])) &&
		  (cp == linet	|| cp[-1] == ':' ||
		   cp[-1] == '\t' || cp[-1] == ' ') &&
		  (cp[j] == '\t'  || cp[j] == ' '||
		   cp[j] == ';'   || cp[j] == '\0' ||
		   cp[j] == '\n')) {
			ocur = 1;
			strcpy(opcode, OpCodes[i]);
			break;
		  }
	}
	return (ocur ? cp : NULL);
}

int getsign(char linet[], char cpos[], char sign[]) {
	int i;
	char *si;

	for (i = 0, si = linet; (*si == ' ' || *si == '\t'); ++si);
	if (cpos != si) {
		for (; si < cpos; si++){
			if (*si == ' ' || *si == '\t') continue;
			sign[i++] = *si;
		}
	}
	sign[i++] = '\t';
	sign[i] = '\0';
	return (i-1);
}

int getopcode(char si[], char comment[], char oppart[]) {
	int ocur = 0;
	char *cpos, *cpcom;

	/* si point to the stoken behind opcode */
	if (*si != '\n') {
		cpos = si;
		if (NULL != (cpcom = strchr(si, ';'))){
			ocur = 1;
			strcat(comment, cpcom);
			while(*--cpcom == '\t' || *cpcom == ' ');
			*(cpcom+1) = '\0';
		}
		if (';' != *(cpos = si)) strcpy (oppart, cpos);
	}else ;
	return ocur;
}

int divtoken(char linet[]) {
	char *si, *cpos;
	char sign[50] = "\0",
	  opcode[10] = {0},
	  oppart[MAXLINE] = {0},
	  comment[MAXLINE] = "\t\t";
	int cmtocur = 0;

	if (!(cpos = opocur(linet, opcode)))
		return 0;
	getsign(linet, cpos, sign);

	cpos += strlen(opcode);
	for (si = cpos; (*si == ' ' || *si == '\t')
	  && *si != '\n'; ++si);
	cmtocur = getopcode(si, comment, oppart);

	strcpy (linet, sign);
	strcat (linet, opcode);

	if (addblank(oppart) > 0) {
		strcat(linet, "\t");
		strcat (linet, oppart);
	}
	if (cmtocur) strcat (linet, comment);
	return 1;
}

int addblank(char *line){
	char delim[10] = "\t, ", *p;
	char linet[64];

	if (strlen(line) == 0)
		return 0;
	strcpy(linet, strtok(line, delim));
	if (linet[0] == '\0')
		return 0;

	while (p = strtok(NULL, delim)) {
		strcat (linet, ", ");
		strcat (linet, p);
	}

	strcpy(line, linet);
	return 1;
}

/*read a line and return the length of it*/
int getline(char s[]){
	int c, i;

	for(i = 0; (c = fgetc(stdin)) != EOF && c != '\n'; ++i)
		s[i] = c;
	s[i] = '\0';
	return (c == EOF)? -1: i;
}

/*copy string from array arg2 to array arg1*/
void copy(char to[], char from[]){
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
