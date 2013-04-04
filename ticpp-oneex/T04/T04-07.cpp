//: T04:T04-07.cpp
//让Stash存放25个double值,并显示它们
//{L} CppLib

#include "CppLib.h"
#include "../require.h"
#include <iostream>
using namespace std;

int const d_count = 3;	// 25;

int main() {
	Stash dStash;
	dStash.initialize(sizeof(double));

	cout <<"input " <<d_count <<" double numbers" <<endl;
	double d;
	for (int i = 0; i < d_count; i++) {
		cin >>d;
		dStash.add(&d);
	}

	for (int i = 0; i < d_count; i++) {
		cout <<*(double*)dStash.fetch(i) <<endl;
	}
	dStash.cleanup();

	return 0;
} ///:~
