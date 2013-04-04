//: T05:T05-14.cpp
//使用Cheshire cat技术
//创建类StackOfInt
//并测试它
//{L} StackOfInt

#include "StackOfInt.h"
#include <iostream>
using namespace std;

int main() {
	StackOfInt s;
	s.initialize();
	for (int i = 100; i < 125; i++) {
		s.push(i);
	}

	int d;
	while (s.pop(&d) >= 0) {
		cout <<" " <<d;
	}
	cout <<endl;
	s.cleanup();
	return 0;
} ///:~
