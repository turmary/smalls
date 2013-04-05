/* FSM:Finite State Machine, 有限状态机*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag{IDENTIFIER, QUALIFIER, TYPE}/*nextstate*/;

struct token{
	char type;
	char string[MAXTOKENLEN];
};

int top = -1;

/* 在第一个标识符(identifier)前保存所有的标记(token) */
struct token stack[MAXTOKENS];
/* 保存刚读入的标记 */
struct token cur;

#define pop stack[top--]
#define push(s) stack[++top] = s

/* 推断标识符的类型 */
enum type_tag classify_string(void){
	char *s = cur.string;
	if(!strcmp(s, "const")){
		strcpy(s, "read_only");
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
		strcpy(cur.string, "pointer to ");
		cur.type = '*';
		return;
	}
	cur.string[1] = '\0';
	cur.type = *p;
	return;
}

/* 理解所有分析过程的代码段 */
read_to_first_identifer(){
	gettoken();
	while(cur.type != IDENTIFIER){
		push(cur);
		gettoken();
	}
	printf("%s is ", cur.string);
	gettoken();
}

deal_with_arrays(){
	while(cur.type == '['){
		printf("array ");
		gettoken();
		/* 数字或']' */
		if(isdigit(cur.string[0])){
			printf("0..%d ", atoi(cur.string) - 1);
			gettoken();
		}
		gettoken();
		printf("of ");
	}
}

deal_with_function_args(){
	while(cur.type != ')') {
		gettoken();
	}
	gettoken();
	printf("function returning ");
}

deal_with_pointers(){
	while(stack[top].type == '*'){
		printf("%s ", pop.string);
	}
}

deal_with_declarator(){
	/*处理标识符之后可能存在的数组/函数 */
	switch(cur.type){
		case '[':
			deal_with_arrays();
			break;
		case '(':
			deal_with_function_args();
	}

	deal_with_pointers();

	/* 处理在读入到标识符之前压入到堆栈中的符号 */
	while(top >= 0){
		if(stack[top].type == '('){
			pop;
			gettoken();
			deal_with_declarator();
		}else{
			printf("%s ", pop.string);
		}
	}
}

main(){
	/* 将标记压入堆栈中,直到遇见标识符 */
	read_to_first_identifer();
	deal_with_declarator();
	printf("\n");
	return 0;
}

/*
void get_lparen(){
	nextstate = get_ptr_part;
	if(top >= 0){
		if(stack[top].type == '('){
			pop;
			gettoken();	*//* 从')'之后读取 *//*
			nextstate = get_array();
		}
	}
}

void get_ptr_part(){
	nextstate = get_type;
	if(stack[top].type == '*'){
		printf("pointer to ");
		pop;
		nextstate = get_lparen();
	}else if(stack[top].type == QUALIFIER){
		printf("%s ", pop.string);
		nextstate = get_lparen();
	}
}

void get_type(){
	nextstate = NULL;
*/	/* 处理在读入标识符之前放在堆栈里的所有标记 */
/*	while(top >= 0){
		printf("%s ", pop.string);
	}
	printf("\n");
}
*/