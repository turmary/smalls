//: T16:T16-21.cpp
// Repeat Exercise 20 using vector instead of Stack
#include "OStack.h"
#include "../require.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Use multiple inheritance. We want 
// both a string and an Object:
class MyString: public string, public Object {
public:
	~MyString() {
		cout <<"deleting string: " <<*this <<endl;
	}
	MyString(string s) : string(s) {}
	MyString() : string("") {}
};

int main(int argc, char* argv[]) {
	requireArgs(argc, 1); // File name is argument
	ifstream in(argv[1]);
	assure(in, argv[1]);

	vector<MyString*> textlines;
	string line;
	// Read file and store lines in the stack:
	while (getline(in, line)) {
		textlines.push_back(new MyString(line));
	}

	// Pop some lines from the stack:
	MyString* s;
	for (int i = 0; i < 10; i++) {
		if((s = textlines.back()) == 0) {
			break;
		}
		textlines.pop_back();

		cout <<*s <<endl;
		delete s;
	}
	cout <<"Letting the destructor do the rest:" <<endl;

	return 0;
} ///:~
