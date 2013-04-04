//: T04:T04-08.cpp
//让Stack存放25个double值,并显示它们
//{L} Stack

#include "Stack.h"
#include "../require.h"
#include <iostream>
using namespace std;

int const d_count = 3;	// 25;

int main() {
	Stack ds;
	ds.initialize();

	cout <<"input " <<d_count <<" double numbers" <<endl;
	double d;
	for (int i = 0; i < d_count; i++) {
		cin >>d;
		ds.push(new double(d));
	}

	double* dp;
	for (; (dp = (double*)ds.pop());) {
		cout <<*dp <<endl;
		delete dp;
	}
	ds.cleanup();

	return 0;
} ///:~
