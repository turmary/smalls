//: T13:T13-08.cpp
//{L} Counted
// ��new������Counted
// �����deleteÿ��Counted����

#include "Counted.h"
#include <iostream>
using namespace std;

int main(int, char* []) {
	cout <<"Enter main()" <<endl;

	const int count = 100;

	Counted* p = new Counted[count];

	for (int i = 0; i < count; i++) {
		delete &p[i];
	}

	void* vp = static_cast<void*>(new Counted());
	// warning: delteing 'void*' is undefined
	delete vp;

	cout <<"Exit main()" <<endl;
	return 0;
} ///:~
