//: T14:T14-27.cpp
// creates the design pattern called proxy

#include <iostream>
using namespace std;

class Subject {
public:
	virtual int f() = 0;
	virtual int g() = 0;
	virtual int h() = 0;
};

class Proxy: public Subject {
	Subject* sub;
public:
	Proxy() {
		sub = NULL;
	}
	Proxy(Subject* s) {
		sub = s;
	}
	~Proxy() {
		if (sub != NULL) {
			delete sub;
		}
	}
	void setSubject(Subject* s) {
		if (sub != NULL) {
			delete sub;
		}
		sub = s;
	}
	int f() { return sub->f(); }
	int g() { return sub->g(); }
	int h() { return sub->h(); }
};

class Implementation1: public Subject {
public:
	int f() { return 10000; }
	int g() { return 10001; }
	int h() { return 10002; }
};

class Implementation2: public Subject {
public:
	int f() { return 20000; }
	int g() { return 20001; }
	int h() { return 20002; }
};


int main(int argc, char* argv[]) {
	Proxy* proxy;

	proxy = new Proxy(new Implementation1);

	cout <<proxy->f() <<endl;
	cout <<proxy->g() <<endl;
	cout <<proxy->g() <<endl;

	proxy->setSubject(new Implementation2);

	cout <<proxy->f() <<endl;
	cout <<proxy->g() <<endl;
	cout <<proxy->g() <<endl;

	return 0;
} ///:~
