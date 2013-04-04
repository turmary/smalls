//: T13:T13-06.cpp
//{L} Counted
//{L} PStash
// 给Counted类添加函数f()
// 遍历PStash并调用f()

#include "Counted.h"
#include "PStash.h"
#include <iostream>
using namespace std;

int main(int, char* []) {
	cout <<"Enter main()" <<endl;

	PStash psh;

	for (int i = 0; i < 7; i++) {
		psh.add(new Counted());
	}

	for (int i = 0; i < psh.count(); i++) {
		static_cast<Counted*>(psh[i])->f();
	}
	
	for (int i = 0; i < psh.count(); i++) {
		Counted* p;
		p = static_cast<Counted*>(psh.remove(i));
		delete p;
	}

	cout <<"Exit main()" <<endl;
	return 0;
} ///:~
