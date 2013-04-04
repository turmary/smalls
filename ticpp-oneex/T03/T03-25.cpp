//: T03:T03-25.cpp
//定义一个float变量
//转换其地址为unsigned char指针后
//使用printBinary输出
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
