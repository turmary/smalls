//: T09:T09-04.cpp
//��������������ͬ�ĺ���f1()��f2()
//f1()����������, f2()�Ƿ���������

#pragma(O1)

#include <ctime>
#include <iostream>
using namespace std;

inline int f1(int h) {
	return 2 * h;
}

volatile int f2(int h) {
	return 2 * h;
}

const int COUNT = 50000000;
volatile int r;

int main(void) {
	clock_t t0 = clock();
	for (int i = 0; i < COUNT; i++) {
		r = f1(i);
	}

	clock_t t1 = clock();

	for (int i = 0; i < COUNT; i++) {
		r = f2(i);
	}

	clock_t t2 = clock();

	cout <<"inline function f1 used times = " <<(t1 - t0) <<endl;
	cout <<"non-inline function f2 used times = " <<(t2 - t1) <<endl;

	return 0;
} ///:~
