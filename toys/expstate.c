/*
����: ExpState.C
����: ����һ��������, ����ֵ
����: Tary
����: 2007-05-27
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

enum tagSM_COLUMN{
	/*����, ����,С����,��ĸE, �����ַ� */
	SMSIGN, SMDIGIT, SMDOT, SME, SMOTHER
}SM_COLUMN;

/* ״̬ת������				*/
/* ������ ---- ��ǰ״̬			*/
/* ������ ---- ��ǰ��ȡ���ַ�����	*/
/* Ԫ��ֵ ---- ��һ״̬			*/
char SM[9][5] = {
	{ 1,  2,  3, 10, 10},
	{10,  2,  3, 10, 10},
	{ 9,  2,  4,  6,  9},
	{10,  5, 10, 10, 10},
	{ 9,  5,  9,  6,  9},
	{ 9,  5,  9,  6,  9},
	{ 7,  8, 10, 10, 10},
	{10,  8, 10, 10, 10},
	{ 9,  8,  9,  9,  9}};


/* ���ܵ������� 			*/
/* ������ ---- ��ǰ״̬			*/
/* ������ ---- ��ǰ��ȡ���ַ�����	*/
/* Ԫ��ֵ ---- Ҫִ�еĹ��ܺ���Fx	*/
/*             �±�x(0-7)		*/
char FM[9][5] = {
	{1, 2, 0, 7, 7},
	{7, 2, 0, 7, 7},
	{6, 2, 0, 0, 6},
	{7, 3, 7, 7, 7},
	{6, 3, 6, 0, 6},
	{6, 3, 6, 0, 6},
	{4, 5, 7, 7, 7},
	{7, 5, 7, 7, 7},
	{6, 5, 6, 6, 6}};


int nsign = 1, npsign = 1;		/* β������, �������	*/
long nmpart = 0, nppart = 0;		/* β����������, ����	*/
float fdpart = 0.0, fresult = 0.0;	/* β��С������, ����ֵ	*/

/*�ղ���*/
int f0(char ch){
	return 0;
};

/*��β������ */
int f1(char ch){
	if (ch == '-')
		nsign = -1;
	return 0;
};

/*��β����������*/
int f2(char ch){
	nmpart = nmpart * 10 + (ch - '0');
	return 0;
};

/*��β��С������*/
int f3(char ch){
	static float fds;

	if (!ch) {
		fds = 0.1;
		fdpart = 0.0;
	} else {
		fdpart += fds * (ch - '0');
		fds *= 0.1;
	}
	return 0;
};

/*�������� */
int f4(char ch){
	if (ch == '-')
		npsign = -1;
	return 0;
};

/*����� */
int f5(char ch){
	nppart = nppart * 10 + (ch - '0');
	return 0;
};

/*�������������ֵ */
int f6(char ch){
	fresult = nsign * (nmpart + fdpart) * pow(10, npsign * nppart);
	return 0;
};

/*���ִ��� */
int f7(char ch){
	fresult = 0.0;
	fprintf(stderr, "error resulution of the float number\n");
	return 0;
};

int (*f[8])(char ch) = {f0, f1, f2, f3, f4, f5, f6, f7};


/* ȡ���ַ����� */
int chType(char ch){
	if (ch == '+' || ch == '-'){
		return SMSIGN;
	} else if (isdigit(ch)) {
		return SMDIGIT;
	} else if (ch == '.'){
		return SMDOT;
	} else if (ch == 'E' || ch == 'e') {
		return SME;
	};
	return SMOTHER;
}


/*״̬����ִ�в��� */
int getExp(void){
	static int nState = 0;
	char ch;

	/*
	Use a finite state machine
	to caculate the values of float point string
	*/
	f3(0);
	while (nState < 9) {
		ch = getchar();
		(f[FM[nState][chType(ch)]])(ch);
		nState = (int)SM[nState][chType(ch)];
	}
	if (nState == 10)
		return 1;
	return 0;
}

int main(int argc,char *argv[])
{
	if (!getExp())
		printf("getExp()=%.3e\n", fresult);
	return 0;
}
