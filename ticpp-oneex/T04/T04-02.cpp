//: T04:T04-02.cpp
//创建一个有单个成员函数的struct

#include <iostream>
#include <string>
using namespace std;

struct OnlyOne {
	string onlyMember(void);
};

string OnlyOne::onlyMember(void) {
	return string(__FUNCTION__) + "()";
}

int main() {
	OnlyOne onlyOne;

	cout <<onlyOne.onlyMember() <<endl;
	return 0;
} ///:~
