//: T01:T01-02.cpp
// Create a class with inner exception type
// with argument const char*.
#include <iostream>
using namespace std;

class OuterExp {
public:
	struct exp_obj {
		const char* desc;
		exp_obj(const char* s): desc(s) {}
	};
	void throw_exp(void) {
		throw exp_obj("from OuterExp::throw_exp");
	}
};

int main(void) {
	OuterExp t;

	try {
		t.throw_exp();
	} catch (OuterExp::exp_obj & e) {
		cout << e.desc;
	}
} ///:~
