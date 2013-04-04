//: T16:T16-12.cpp
// Modify TStack2.h so that it uses a Standard C++ Library
// vector as its underlying implementation. Make sure that
// you don't change the interface, so that TStack2Test.cpp
// works unchanged.
#include "TStackVector.h"
#include "../require.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	const char* filename;

	filename = "T16-12.cpp";
	if (argc >= 2) {
		filename = argv[1];
	}
	ifstream file(filename);
	assure(file, filename);

	Stack<string> textlines;
	// Read file and store lines in the Stack:
	string line;
	while (getline(file, line)) {
		textlines.push(new string(line));
	}

	int i = 0;
	// Use iterator to print lines from the list:
	Stack <string>::iterator it = textlines.begin();
	Stack <string>::iterator * it2 = 0;
	while (it != textlines.end()) {
		cout <<it->c_str() <<endl;
		if (++i == 10) {
			// Remember 10th line
			it2 = new Stack<string>::iterator(it);
		}
		it++;
	}
	cout <<(*it2)->c_str() <<endl;
	delete it2;
}
///:~
