//: T03:T03-25.cpp
//����һ��float����
//ת�����ַΪunsigned charָ���
//ʹ��printBinary���
//{L} printBinary

#include "printBinary.h"
#include <iostream>
using namespace std;

int main() {
	float f = 128.0;
	unsigned char* p;

	p = reinterpret_cast<unsigned char*>(&f);

	for (int i = 0; i < sizeof(float); i++) {
		printBinary(*p++);
	}
	cout <<endl;

	return 0;
} ///:~
