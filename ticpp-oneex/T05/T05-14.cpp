//: T05:T05-14.cpp
//ʹ��Cheshire cat����
//������StackOfInt
//��������
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
