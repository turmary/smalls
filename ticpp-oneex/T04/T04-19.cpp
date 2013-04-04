//: T04:T04-19.cpp
//创建嵌套的struct结构
//并定义它的数据成员和成员函数

#include <iostream>
using namespace std;

struct Outer{
	struct Inner{
		int innerMember;
		int innerFunction(int dummy);
	};

	int outerMember;

	int outerFunction(int dummy);
};

int Outer::Inner::innerFunction(int dummy) {
	cout <<"Outer::Inner::" << __FUNCTION__ <<"()" <<endl;
	cout <<"Outer::Inner::innerMember = " <<innerMember <<endl;
	return dummy;
}

int Outer::outerFunction(int dummy) {
	cout <<"Outer::" << __FUNCTION__ <<"()" <<endl;
	cout <<"Outer::outerMember = " <<outerMember <<endl;
	return dummy;
}

int main() {
	Outer a;
	Outer::Inner b;

	a.outerMember = 5;
	b.innerMember = 3;

	a.outerFunction(2);
	b.innerFunction(4);

	return 0;
} ///:~
