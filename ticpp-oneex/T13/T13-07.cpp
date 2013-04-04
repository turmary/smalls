//: T13:T13-07.cpp
//{L} Counted
// ��Counted����Ӻ���f()
// ����Stack������f()

#include "Counted.h"
#include "Stack4.h"
#include <iostream>
using namespace std;

int main(int, char* []) {
	cout <<"Enter main()" <<endl;

	Stack psh;

	for (int i = 0; i < 7; i++) {
		psh.push(new Counted());
	}

	while (psh.peek()) {
		Counted* p = static_cast<Counted*>(psh.pop());
		p->f();
		delete p;
	}

	cout <<"Exit main()" <<endl;
	return 0;
} ///:~
