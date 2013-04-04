//: T04:T04-04.cpp
//定义含有一个int数据成员的struct

#include <iostream>
#include <string>
using namespace std;

struct HasInt{
	int i;
};

int intSet(HasInt* hip, int i) {
	hip->i = i;
	return i;
}

int intView(HasInt* hip) {
	cout <<"i = " <<hip->i <<endl;
}

int main() {
	HasInt hi;

	intSet(&hi, 5);
	intView(&hi);
	return 0;
} ///:~
