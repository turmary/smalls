//: T08:T08-04.cpp
//��ͷ�ļ��д���һ��const����
//��������.cpp�ļ���ʹ����

#include "cnsthdr.h"
#include <ctime>
#include <iostream>
using namespace std;

int hello(void);

extern const int xxx_handler;

int main() {
	hello();
	cout <<"cnst_integer_val = " <<cnst_integer_val <<endl;

	const time_t t1 = time(NULL);

	for (; t1 == time(NULL);) {
		;
	}
	const time_t t2 = time(NULL);
	cout <<"t1 = " <<t1 <<endl;
	cout <<"t2 = " <<t2 <<endl;

	cout <<"xxx_handler = " <<xxx_handler <<endl;
	return 0;
} ///:~
