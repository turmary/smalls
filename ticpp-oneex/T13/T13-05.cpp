//: T13:T13-05.cpp
//{L} Counted
// 给Counted类添加函数f()
// 遍历vector并调用f()

#include "Counted.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int, char* []) {
	cout <<"Enter main()" <<endl;

	vector<Counted*> psh;
	vector<Counted*>::iterator it;

	for (int i = 0; i < 7; i++) {
		psh.push_back(new Counted());
	}

	for (it = psh.begin(); it != psh.end(); it++) {
		(*it)->f();
	}
	
	for (it = psh.begin(); it != psh.end(); it++) {
		delete *it;
	}

	cout <<"Exit main()" <<endl;
	return 0;
} ///:~
