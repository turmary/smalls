//: T05:T05-10.cpp
// Write a class template that takes two type parameters.
// Define a partial specialization for the first parameter,
// and another partial specialization that specifies the second parameter.
// In each specialization, introduce members that are not in the primary template.
#include <iostream>
#include "../require.h"
using namespace std;

template<class R, class S >
struct classSpec {
	classSpec() {
		cout <<"Class Spec R & S" <<endl;
	}
};

template<class S>
struct classSpec<int, S> {
	classSpec() {
		cout <<"Class Spec R" <<endl;
	}
	void _S() {
		cout <<"Class Spec R size:" <<sizeof(*this) <<endl;
	}
};

template<class R>
struct classSpec<R, double> {
	classSpec() {
		cout <<"Class Spec S" <<endl;
	}
	void _R() {
		cout <<"Class Spec S size:" <<sizeof(*this) <<endl;
	}
};

int main(int argc, char* argv[]) {
	classSpec<int,long> intlong;
	intlong._S();

	// invalid
	// classSpec<char, float> charfloat;
	classSpec<char, double> charfloat;
	charfloat._R();

	classSpec<char, float> classRS;
	return 0;
}
///:~
