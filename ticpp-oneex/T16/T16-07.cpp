//: T16:T16-07.cpp
// Modify AutoCounter.h so that it can be used as a
// member object inside any class whose creation and
// destruction you want to trace. Add a string member to
// hold the name of the class. Test this tool inside a class
// of you own.
#include <iostream>
#include <string>
#include "AutoCheck.h"
#include "../require.h"
using namespace std;

class any_class {
	static int cnt;
	AutoCheck autochk;
public:
	int i;
	any_class(): i(cnt++) {
	}
	any_class(const any_class& r): i(cnt++) {
		i = r.i + 1000;
	}
	~any_class() {
		// delete x;
	}
};

int any_class::cnt = 0;

int func__(const any_class ac) {
	cout <<"ac=" <<ac.i <<endl;
	return 0;
}

int main(int argc, char* argv[]) {
	any_class *x = new any_class;
	any_class b = *x;
	cout <<"Create any_class " <<b.i <<" complete" <<endl;

	func__(*new any_class);
	cout <<"Create first any_class " <<x->i <<endl;
	delete x;
}///:~
