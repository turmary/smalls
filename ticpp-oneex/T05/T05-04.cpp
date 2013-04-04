//: T05:T05-04.cpp
//创建两个类,每个类有一个成员数
//函数中将指针指向另一个类的一个对象

#include <iostream>
using namespace std;

class first {
public:
	int member(int deep);
};

class second {
public:
	int member(int deep);
};

int first::member(int deep) {
	if (deep == 0) {
		return 0;
	}
	cout <<"first deep = " <<deep <<endl;
	second two;
	second* p = &two;
	return p->member(--deep);
}

int second::member(int deep) {
	if (deep == 0) {
		return 0;
	}
	cout <<"second deep = " <<deep <<endl;
	first one;
	first* p = &one;
	return p->member(--deep);
}

int main() {
	int deep = 10;

	first one;
	one.member(deep);
	return 0;
} ///:~
