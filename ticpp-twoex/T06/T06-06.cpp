//: T06:T06-06.cpp
// Create a class hierarchy with a base class B and a derived class D.
// Put a virtual member function void f() in B such that
// it will print a message indicating that B’s f() was called,
// and redefine this function for D to print a different message.
// Create a vector<B*>, and fill it with B and D objects.
// Use for_each( ) to call f() for each of the objects in your vector.
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <unistd.h>
#include "../require.h"
using namespace std;

class B {
public:
	virtual void f() {
		cout <<"B::f()" <<endl;
	}
};

class D: public B {
public:
	virtual void f() {
		cout <<"D::f()" <<endl;
	}
};

int main(int argc, const char* argv[]) {
	vector<B*> vb;

	vb.push_back(new B());
	vb.push_back(new D());
	for_each(vb.begin(), vb.end(), mem_fun(&B::f));

	return 0;
}
///:~

