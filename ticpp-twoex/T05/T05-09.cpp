//: T05:T05-09.cpp
// Write templates that take non-type parameters of the following variety:
//   an int,
//   a pointer to an int,
//   a pointer to a static class member of type int,
//   and a pointer to a static member function.
#include <iostream>
#include "../require.h"
using namespace std;

template<int N>
struct intNonType {
	int array[N];
	intNonType() { cout <<array[0] <<endl; }
};

template<int* IP>
struct intpNonType {
	intpNonType() {
		cout <<IP <<endl;
	}
};

template<typename T, int T::* IP >
struct classIntNonType {
	classIntNonType() {
		cout <<IP <<endl;
	}
};

template<typename T, int (T::* funcp)(void) >
struct classFuncNonType {
	classFuncNonType() {
		cout <<funcp <<endl;
	}
};

template<typename T, int (*funcp)(void) >
struct classFuncStaticNonType {
	classFuncStaticNonType() {
		cout <<funcp <<endl;
	}
};

struct innerClass{
	int x;
	static int sx;
	static int sprint(void) {
		cout <<sx <<endl;
		return sx;
	}
	int print(void) {
		cout <<x <<endl;
		return x;
	}
} ic;

int innerClass::sx = 5;
int* ip = &innerClass::sx;

int globalVar; // must has linkage
int main(int argc, char* argv[]) {
	const int n  = 5;
	// const variable
	intNonType<n> intNonType5;
	// global variable pointer
	intpNonType<&globalVar> intpNonTypep;
	// member variable
	intpNonType<&innerClass::sx> innerClassStaticNonTypep;
	classIntNonType<innerClass, &innerClass::x > classIntNonTypeI;
	// member function
	classFuncStaticNonType<innerClass, &innerClass::sprint > classFuncStaticNonTypeI;
	classFuncNonType<innerClass, &innerClass::print > classFuncNonTypeI;
	return 0;
}
///:~
