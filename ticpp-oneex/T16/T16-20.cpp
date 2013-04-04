//: T16:T16-20.cpp
// Modify C15:OStack.h and C15:OStackTest.cpp by
// templatizing class Stack so that it automatically multiply
// inherits from the contained class and from Object. The
// generated Stack should accept and product only pointers
// of the contained type.
#include "OStack.h"
#include "../require.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Use multiple inheritance. We want 
// both a string and an Object:
class MyString: public string, public Object {
public:
	~MyString() {
		cout <<"deleting string: " <<*this <<endl;
	}
	MyString(string s) : string(s) {}
	MyString() : string(""), Object() {}
};

int main(int argc, char* argv[]) {
	requireArgs(argc, 1); // File name is argument
	ifstream in(argv[1]);
	assure(in, argv[1]);

	Stack<MyString> textlines;
	string line;
	// Read file and store lines in the stack:
	while (getline(in, line)) {
		textlines.push(new MyString(line));
	}

	// Pop some lines from the stack:
	MyString* s;
	for(int i = 0; i < 10; i++) {
		if((s = (MyString*)textlines.pop()) == 0) {
			break;
		}
		cout <<*s <<endl;
		delete s;
	}
	cout <<"Letting the destructor do the rest:" <<endl;
} ///:~
