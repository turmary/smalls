//: T05:T05-05.cpp
//创建三个类
//第一个类包含private数据
//并且每二和每三个类的成员函数是它的友元

#include <iostream>
using namespace std;

class first;

class second {
public:
	int visit_1st(first* fir);
};

class third {
public:
	int visit_1st(first* fir);
};

class first {
private:
	int val;
	friend int second::visit_1st(first* fir);
	friend int third::visit_1st(first* fir);
public:
	int print(void) {
		cout <<"first.val = " <<val <<endl;
		return 0;
	}
};

int second::visit_1st(first* fir) {
	cout <<__FUNCTION__ <<"()" <<endl;
	fir->val = 2;
	return 2;
}

int third::visit_1st(first* fir) {
	cout <<__FUNCTION__ <<"()" <<endl;
	fir->val = 3;
	return 3;
}

int main() {
	first fir;
	second sec;
	third thd;

	fir.print();
	sec.visit_1st(&fir);
	fir.print();
	thd.visit_1st(&fir);
	fir.print();
	return 0;
} ///:~
