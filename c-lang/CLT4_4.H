#include <ctype.h>
#define D_S_STACK 0

#define MAXVAL 100
static int sp = 0;
static double val[MAXVAL];

void push(double f){
	if(sp < MAXVAL){
		val[sp++] = f;
#if D_S_STACK
		printf("PUSH TOP=%10.6f\n", f);
#endif
	}else
		printf("error: stack full, can't push %g\n in push()", f);
}

double getTop(void){
	if( sp > 0){
		return val[sp - 1];
	}else{
		printf("error: stack empty in getTop()\n");
		return -1;
	}
}

double copyTop(void){
	if(sp > 0)
		if(sp < MAXVAL){
			return val[sp++] = val[sp - 1];
		}else{
			printf("error: stack full in copyTop()\n");
			return -1;
		}
	else{
		printf("error: stack empty in copyTop()\n");
		return -2;
	}
}

void swapTop2(void){
	double t;

	if(sp > 1){
		t = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = t;
	}else{
		printf("error: stack no enough in swapTop2()\n");
	}
}

void cStack(void){
	sp = 0;
}

double pop(void){
	if(sp > 0){
#if D_S_STACK
		printf("GET TOP=%10.6f\n", val[sp-1]);
#endif
		return val[--sp];
	}else{
		printf("error: stack empty in pop()\n");
		return -1;
	}
}

#define D_S_MAIN 0
#if D_S_MAIN
int main(){
	clrscr();
	push(8.0);
	printf("push(8.0) Top = %lf\n", getTop());
	push(-20.0);
	printf("push(-20.0) Top = %lf\n", getTop());
	swapTop2();
	printf("swapTop2() Top = %lf\n", getTop());
	printf("Pop = %lf\n", pop());
	cStack();
	printf("cStack() Top = %lf\n", getTop());
	return 0;
}
#endif