/* CDECL, �������з������̵Ĵ���� */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKENS 100
#define MAXTOKENLEN 64
#define pop stack[top--]
#define push(s) stack[++top] = s

enum type_tag{IDENTIFIER, QUALIFIER, TYPE};
struct token{
	char type;
	char string[MAXTOKENLEN];
};
int top = -1;
/* �ڵ�һ����ʶ��(identifier)ǰ�������еı��(token) */
struct token stack[MAXTOKENS];
/* ����ն���ı�� */
struct token cur;

enum type_tag classify_string(void);
void gettoken(void);
void read_to_first_identifer();
void deal_with_arrays();
void deal_with_declarator();
void deal_with_function_args();
void deal_with_pointers();

int main(void){
	/* �����ѹ���ջ��,ֱ��������ʶ�� */
	read_to_first_identifer();
	deal_with_declarator();
	printf("��\n");
	return 0;
}

/* �ƶϱ�ʶ�������� */
enum type_tag classify_string(void){
	char *s = cur.string;
	if(!strcmp(s, "const")){
		strcpy(s, "ֻ��");
		return QUALIFIER;
	}
	if(!strcmp(s, "volatile"))return QUALIFIER;
	if(!strcmp(s, "void"))return TYPE;
	if(!strcmp(s, "char"))return TYPE;
	if(!strcmp(s, "signed"))return TYPE;
	if(!strcmp(s, "unsigned"))return TYPE;
	if(!strcmp(s, "short"))return TYPE;
	if(!strcmp(s, "int"))return TYPE;
	if(!strcmp(s, "long"))return TYPE;
	if(!strcmp(s, "float"))return TYPE;
	if(!strcmp(s, "double"))return TYPE;
	if(!strcmp(s, "struct"))return TYPE;
	if(!strcmp(s, "union"))return TYPE;
	if(!strcmp(s, "enum"))return TYPE;
	return IDENTIFIER;
}

void gettoken(void){
	/* ������һ�����,������"cur"�� */
	char *p = cur.string;

	/* �Թ����пհ׷� */
	while((*p = getchar()) == ' ');

	if(isalnum(*p)){
		/* �ڱ�ʶ���ж���a-z, 0-9��ͷ */
		while(isalnum(*++p = getchar()));
		ungetc(*p, stdin);
		*p = '\0';
		cur.type = classify_string();
		return;
	}

	if(*p == '*'){
		strcpy(cur.string, "ָ��\nָ���������� \n");
		cur.type = '*';
		return;
	}
	cur.string[1] = '\0';
	cur.type = *p;
	return;
}

void read_to_first_identifer(){
	gettoken();
	while(cur.type != IDENTIFIER){
		push(cur);
		gettoken();
	}
	printf("\t˵��:\n");
	printf("%s��", cur.string);
	gettoken();
	return;
}

void deal_with_arrays(){
	while(cur.type == '['){
		printf("����\n");
		gettoken();
		/* ���ֻ�']' */
		if(isdigit(cur.string[0])){
			printf("�±��0��%d\n", 
			 atoi(cur.string) - 1);
			gettoken();
		}
		gettoken();
		printf("������Ԫ�����\n");
	}
	return;
}

void deal_with_function_args(){
	/*printf("������������\n");*/
	while(cur.type != ')') {
		gettoken();
		/*printf("%s ", cur.string);*/
	}
	gettoken();
	printf("����\n����");
	return;
}

void deal_with_pointers(){
	while(stack[top].type == '*'){
		printf("%s", pop.string);
	}
	return;
}

void deal_with_declarator(){
	/*������ʶ��֮����ܴ��ڵ�����/���� */
	switch(cur.type){
		case '[':
			deal_with_arrays();
			break;
		case '(':
			deal_with_function_args();
	}

	deal_with_pointers();

	/* �����ڶ�����ʶ��֮ǰѹ�뵽��ջ�еķ��� */
	while(top >= 0){
		if(stack[top].type == '('){
			/* ������ȥ����һ��() */
			pop;
			gettoken();
			/* ��ȡ)֮������� */
			deal_with_declarator();
		}else{
			printf("%s", pop.string);
		}
	}
	return;
}