//: T04:onlyOne.cpp
//创建一个有单个成员函数的struct

#include "onlyOne.h"
#include <string>
using namespace std;

string OnlyOne::onlyMember(void) {
	return string(__FUNCTION__) + "()";
} ///:~
