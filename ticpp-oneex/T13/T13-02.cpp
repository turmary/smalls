//: T13:T13-02.cpp
//{L} Counted
// 通过new创建一个class Counted的对象

#include "Counted.h"
#include <iostream>
using namespace std;

class PreMain {
	PreMain() {
		cout <<"Before enter main()" <<endl;
	}
	PreMain(const PreMain&) { }
	PreMain& operator= (const PreMain&) { }
	~PreMain() {
		cout <<"After exited main()" <<endl;
	}
public:
	static PreMain preMain;
};

PreMain PreMain::preMain;

int main(int, char* []) {
	cout <<"Enter main()" <<endl;

	Counted *pC, cx;

	pC = new Counted();
	delete pC;

	pC = new Counted[5];
	delete []pC;

	cout <<"Exit main()" <<endl;
	return 0;
} ///:~
