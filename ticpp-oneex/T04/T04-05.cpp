//: T04:T04-05.cpp
//���庬��һ��int���ݳ�Ա��struct
//������������Ա����������ֵ����ʾ

#include <iostream>
#include <string>
using namespace std;

struct HasInt{
	int i;

	int intSet(int i) {
		this->i = i;
		return i;
	}

	int intView(void) {
		cout <<"i = " <<this->i <<endl;
	}
};

int main() {
	HasInt hi;

	hi.intSet(5);
	hi.intView();
	return 0;
} ///:~
