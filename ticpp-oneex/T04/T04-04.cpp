//: T04:T04-04.cpp
//���庬��һ��int���ݳ�Ա��struct

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
