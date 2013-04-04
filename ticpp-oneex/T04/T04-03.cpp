//: T04:T04-03.cpp
//创建一个有单个成员函数的struct

#include "onlyOne.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	OnlyOne onlyOne;

	cout <<onlyOne.onlyMember() <<endl;
	return 0;
} ///:~
