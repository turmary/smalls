//: T15:T15-15.cpp
// show the difference between calling a virtual
// function inside a normal member function and
// a constructor.
#include <vector>
#include <iostream>
using namespace std;

class Aircraft {
public:
	Aircraft(void) {
		cout <<"(base)::" <<__FUNCTION__ <<"()" <<endl;
		this->fly();
	}
	Aircraft(Aircraft* pac) {
		cout <<"(base arg)::" <<__FUNCTION__ <<"()" <<endl;
		pac->fly();
	}
	void Normal(void) {
		cout <<"(base)::" <<__FUNCTION__ <<"()" <<endl;
		fly();
	}
	virtual void fly(void) {
		cout <<"(base)::" <<__FUNCTION__ <<"()" <<endl;
	}
};

class First: public Aircraft {
public:
	First(): Aircraft() {
		// cout <<"(first)::" <<__FUNCTION__ <<"()" <<endl;
		// fly();
	}
	virtual void fly(void) {
		cout <<"(first)::" <<__FUNCTION__ <<"()" <<endl;
	}
};

class Second: public Aircraft {
public:
	Second(): Aircraft(this) {
		// cout <<"(second)::" <<__FUNCTION__ <<"()" <<endl;
		// fly();
	}
	virtual void fly(void) {
		cout <<"(second)::" <<__FUNCTION__ <<"()" <<endl;
	}
};

int main(int argc, char* argv[]) {
	Aircraft* pac;

	pac = new First;
	pac->Normal();
	delete pac;
	cout <<"----------" <<endl;

	pac = new Second;
	pac->Normal();
	delete pac;
	cout <<"----------" <<endl;

	return 0;
} ///:~
