//: T05:T05-01.cpp
// Write a unary function template that
// takes a single type template parameter.
// Create a full specialization for the type int.
// Also create a non-template overload for
// this function that takes a single int parameter.
// Have your main program invoke three function variations.
#include <iostream>
#include "../require.h"
using namespace std;

template<class T> T unary_f(T arg) {
	cout <<arg <<endl;
	return arg;
}

template int unary_f<int>(int);

double unary_f(double arg) {
	cout <<"unary f double version: ";
	cout <<arg <<endl;
	return arg;
}

int main(int argc, const char* argv[]) {
	unary_f(3.1416);
	unary_f(3);
	unary_f("string");
	return 0;
}
///:~
