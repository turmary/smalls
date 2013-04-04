//: T12:T12-24.cpp
//创建一个包含string数据成员的类
//初使化这个string成员
//但是不要创建拷贝构造函数和=操作符
//创建第二个类,包含第一个类型的数据成员
//展示它们的拷贝构造函数和=操作符
//被编译器正确地生成了

#include <string>
#include <iostream>
using namespace std;

class inner {
	string s;
public:
	inner(const string si = string("")): s(si) {}
	void print(void) {
		cout <<s <<endl;
	}
};

class outter {
	inner in;
public:
	outter(string s): in(s) {}
	void print(void) {
		in.print();
	}
};

int main(void) {
	outter i = string("hello world");
	outter i2 = i;
	i2.print();
	
	outter i3 = string("i3");
	i = i3;
	i.print();
	return 0;
} ///:~
