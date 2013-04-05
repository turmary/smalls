/* CDECL, 理解所有分析过程的代码段 */
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
/* 在第一个标识符(identifier)前保存所有的标记(token) */
struct token stack[MAXTOKENS];
/* 保存刚读入的标记 */
struct token cur;

enum type_tag classify_string(void);
void gettoken(void);
void read_to_first_identifer();
void deal_with_arrays();
void deal_with_declarator();
void deal_with_function_args();
void deal_with_pointers();

int main(void){
	/* 将标记压入堆栈中,直到遇见标识符 */
	read_to_first_identifer();
	deal_with_declarator();
	printf("型\n");
	return 0;
}

/* 推断标识符的类型 */
enum type_tag classify_string(void){
	char *s = cur.string;
	if(!strcmp(s, "const")){
		strcpy(s, "只读");
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
	/* 读入下一个标记,保存在"cur"中 */
	char *p = cur.string;

	/* 略过所有空白符 */
	while((*p = getchar()) == ' ');

	if(isalnum(*p)){
		/* 在标识符中读入a-z, 0-9开头 */
		while(isalnum(*++p = getchar()));
		ungetc(*p, stdin);
		*p = '\0';
		cur.type = classify_string();
		return;
	}

	if(*p == '*'){
		strcpy(cur.string, "指针\n指向下列内容 \n");
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
	printf("\t说明:\n");
	printf("%s是", cur.string);
	gettoken();
	return;
}

void deal_with_arrays(){
	while(cur.type == '['){
		printf("数组\n");
		gettoken();
		/* 数字或']' */
		if(isdigit(cur.string[0])){
			printf("下标从0到%d\n", 
			 atoi(cur.string) - 1);
			gettoken();
		}
		gettoken();
		printf("由以下元素组成\n");
	}
	return;
}

void deal_with_function_args(){
	/*printf("函数参数如下\n");*/
	while(cur.type != ')') {
		gettoken();
		/*printf("%s ", cur.string);*/
	}
	gettoken();
	printf("函数\n返回");
	return;
}

void deal_with_pointers(){
	while(stack[top].type == '*'){
		printf("%s", pop.string);
	}
	return;
}

void deal_with_declarator(){
	/*处理标识符之后可能存在的数组/函数 */
	switch(cur.type){
		case '[':
			deal_with_arrays();
			break;
		case '(':
			deal_with_function_args();
	}

	deal_with_pointers();

	/* 处理在读到标识符之前压入到堆栈中的符号 */
	while(top >= 0){
		if(stack[top].type == '('){
			/* 这样便去掉了一对() */
			pop;
			gettoken();
			/* 读取)之后的内容 */
			deal_with_declarator();
		}else{
			printf("%s", pop.string);
		}
	}
	return;
}