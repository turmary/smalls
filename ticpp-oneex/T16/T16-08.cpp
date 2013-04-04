//: T16:T16-08.cpp
// Create a version of OwnerStack.h that uses a Standard
// C++ Library vector as its underlying implementation.
// You may need to look up some of the member functions
// of vector in order to do this (or just look at the <vector>
// header file).
//{L} AutoCounter
#include "AutoCounter.h"
#include "OwnerStack.h"
#include "../require.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	Stack<AutoCounter> ac;		// Ownership on
	Stack<AutoCounter> ac2(false);	// Turn it off
	AutoCounter* ap;

	for (int i = 0; i < 10; i++) {
		ap = AutoCounter::create();
		ac.push(ap);
		if (i % 2 == 0) {
			ac2.push(ap);
		}
	}

	while (ac2) {
		cout << ac2.pop() << endl;
	}

	// No destruction necessary since
	// ac "owns" all the objects
}///:~
