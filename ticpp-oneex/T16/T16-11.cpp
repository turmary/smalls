//: T16:T16-11.cpp
// Repeat Execise 9 but use a Standard C++ Library vector
// as the internal implementation of the ValueStack Notice
// how much easier this is.
// {L} SelfCounter
#include "VectorStack.h"
#include "SelfCounter.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	vector<SelfCounter> sc;

	for (int i = 0; i < 25; i++)
		sc.push_back(SelfCounter());

	// OK to peek(), result is a temporary
	cout <<"***** ******" <<endl;
	cout <<sc.back() <<endl;
	cout <<"***** ******" <<endl;

	for (int k = 0; k < 25; k++) {
		cout <<sc.back() <<endl;
		sc.pop_back();
	}

	return 0;
}
///:~
