//: T01:T01-03.cpp
//{L} PStash
// Rewrite the Stash class from Chapter XX so it throws out-of-range 
// exceptions for operator[]. 
#include "PStash.h"
#include <iostream>
#include <string>
using namespace std;

int main(int, char* []) {
	cout <<"Enter main()" <<endl;

	PStash psh;

	for (int i = 0; i < 25; i++) {
		char* buf = new char[32];
		std::sprintf(buf, "psh %d", i);
		psh.add(buf);
	}

	try {
		cout << "psh [ 2] = " <<(const char*)psh[2] <<endl;
		cout << "psh [32] = " <<(const char*)psh[32] <<endl;
	} catch (exception& e) {
		cout << "Catched exception: " <<e.what() <<endl;
	}

	cout <<"Exit main()" <<endl;
	return 0;
} ///:~
