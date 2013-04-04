//: T04:T04-20.cpp
//输出几个结构的大小

#include <iostream>
using namespace std;

struct Empty{};

struct OnlyOne{
	int onlyMember;
};


struct Outer{
	int outerMember;
	int outerFunction(int dummy);
};

int Outer::outerFunction(int dummy) {
	cout <<"Outer::" << __FUNCTION__ <<"()" <<endl;
	cout <<"Outer::outerMember = " <<outerMember <<endl;
	return dummy;
}

int main() {
	cout <<"sizeof Empty = " <<sizeof(Empty) <<endl;		// 1
	cout <<"sizeof OnlyOne = " <<sizeof(OnlyOne) <<endl;		// 4
	cout <<"sizeof Outer = " <<sizeof(Outer) <<endl;		// 4

	return 0;
} ///:~
