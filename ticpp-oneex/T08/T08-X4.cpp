//: T08:T08-04.cpp
//��ͷ�ļ��д���һ��const����
//��������.cpp�ļ���ʹ����

#include "cnsthdr.h"
#include <iostream>
using namespace std;

extern const int xxx_handler = 255;

int hello(void) {
	cout <<"cnst_integer_val = " <<cnst_integer_val <<endl;
	return 0;
} ///:~
