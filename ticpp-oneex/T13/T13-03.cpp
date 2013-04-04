//: T13:T13-03.cpp
//{L} Counted
//{L} PStash
// 创建一个PStash对象
// 并在其中用new创建Counted对象

#include "Counted.h"
#include "PStash.h"
#include <iostream>
using namespace std;

class PreMain {
	PreMain() {
		cout <<"Before enter main()"
		  <<endl;
	}
	PreMain(const PreMain&) { }
	PreMain& operator= (const PreMain&) { }
	~PreMain() { }
public:
	static PreMain preMain;
};

PreMain PreMain::preMain;

int main(int, char* []) {
	cout <<"Enter main()" <<endl;

	PStash psh;

	for (int i = 0; i < 25; i++) {
		psh.add(new Counted());
	}

	cout <<"Exit main()" <<endl;
	return 0;
} ///:~
