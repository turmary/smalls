//: T15:T15-04.cpp
// Modify C14:Combined.cpp so that f() is virtual
// in the base class.

#include <iostream>
using namespace std;

class A {
	int i;
public:
	A(int ii) : i(ii) {}
	~A() {}
	void f() const {
		cout <<"f() in A" <<endl;
	}
};

class B {
	int i;
public:
	B(int ii) : i(ii) {}
	~B() {}
	virtual void f() const {
		cout <<"virtual in B(" <<i <<")" <<endl;
	}
};

class C : public B {
	A a;
public:
	C(int ii) : B(ii), a(ii) {}
	~C() {}			// Calls ~A() and ~B()
	void f() const {	// Redefinition
		a.f();
		B::f();
		cout <<"f() in C" <<endl;
	}
};

int main() {
	C c(47);

	static_cast<B>(c).f();
	c.f();

	return 0;
} ///:~
