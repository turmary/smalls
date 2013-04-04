//: T10:T10-04.cpp
//创建一个类Moniter
//它能知道它的成员的函数incident()被调用了多少次

#include <cstdlib>
#include <iostream>
using namespace std;

class Moniter {
	static int call_count;

public:
	int incident(void) {
		call_count++;
		return 0;
	}

	int decrement(void) {
		call_count--;
		return 0;
	}

	static int print(void) {
		cout <<"call incident() " <<call_count <<" times" <<endl;
		return 0;
	}

	Moniter(void) {
		cout <<__FUNCTION__ <<"()" <<endl;
		return;
	}

	~Moniter(void) {
		cout <<__FUNCTION__ <<"()" <<endl;
		exit(0);
		return;
	}
};

int Moniter::call_count = 0;

class Moniter2 {
	Moniter* pm;

public:
	Moniter2(Moniter* pmii): pm(pmii) {
		cout <<__FUNCTION__ <<"(begin)" <<endl;
		pm->incident();
		pm->print();
		cout <<__FUNCTION__ <<"(end)" <<endl;
		return;
	}

	~Moniter2(void) {
		cout <<__FUNCTION__ <<"(begin)" <<endl;
		pm->decrement();
		pm->print();
		cout <<__FUNCTION__ <<"(end)" <<endl;
		return;
	}
};

int get_call_count(void) {
	static Moniter mon;

	mon.print();
	return 0;
}

Moniter mon;

int static_moniter2(void) {
	static Moniter2 mon2(&mon);

	return 0;
}

static Moniter2 mon2(&mon);

int main() {
#if 0
	//Moniter::incident();
	get_call_count();

	Moniter m;
	m.incident();
	get_call_count();

	Moniter* pm;
	pm->incident();
	get_call_count();

	pm->decrement();
	get_call_count();
#endif

	for (int i = 0; i < 5; i++) {
		// static_moniter2();
	}

	return 0;
} ///:~
