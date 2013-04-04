//: T03:T03-01.cpp
//{L} VarFunc
// 调用可变参数函数

#include "VarFunc.h"
#include <iostream>
using namespace std;

int main(int, char* []) {
	cout <<"Enter main()" <<endl;

	void_vfunc(2, "hello", "world");

	char c = char_vfunc(5, 'h', 'e', 'l', 'l', 'o');

	int i = int_vfunc(1, 25);

	float f = float_vfunc(3, 24.0, 38.0, 55.0);

	cout <<"Exit main()" <<endl;
	return 0;
} ///:~
