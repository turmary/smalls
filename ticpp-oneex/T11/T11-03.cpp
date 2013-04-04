//: T11:T11-03.c
//创建一个引用

#include <iostream>
using namespace std;

struct One {
	int f(void) const {
		cout <<__FUNCTION__ <<"()" <<endl;
		return 1;
	}

	int g(int i) const {
		cout <<__FUNCTION__ <<"(" <<i <<")" <<endl;
		return 2;
	}
};

int h(One* const o) {
	return o->g(o->f());
}

struct Two {
	int cf(void) const {
		cout <<__FUNCTION__ <<"()" <<endl;
		return 1;
	}
	
	int ncg(int i) {
		cout <<__FUNCTION__ <<"(" <<i <<")" <<endl;
		return 2;
	}
};

int x(Two t) {
	return t.ncg(t.cf());
}

int y(Two& t) {
	return t.ncg(t.cf());
}

int z(const Two& t) {
	return (*(Two*)&t).ncg(t.cf());
}

int main(void) {
	int i = 5;
	int b = 10;

	int& iref = *(int*)&i;

	iref = b;
	iref = 3;
	cout <<"i    = " <<i <<endl;
	cout <<"iref = " <<iref <<endl;
	cout <<"b    = " <<b <<endl;

	One one;
	cout <<"h()  = " <<h(&one) <<endl;

	Two t;
	cout <<"x()  = " <<x(t) <<endl;
	cout <<"y()  = " <<y(t) <<endl;
	cout <<"z()  = " <<z(t) <<endl;

	return 0;
} ///:~
