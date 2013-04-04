//: T04:T04-05.cpp
//定义含有一个int数据成员的struct
//并定义两个成员函数用于置值和显示

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
