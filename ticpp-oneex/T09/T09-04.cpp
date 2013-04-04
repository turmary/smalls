//: T09:T09-04.cpp
//创建两个功能相同的函数f1()和f2()
//f1()是内联函数, f2()是非内联函数

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
