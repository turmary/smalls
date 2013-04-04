//: T03:T03-16.cpp
//编制一个使用颜色枚举类型的程序

#include <iostream>
using namespace std;

enum COLOR {
	RED = 255,
	GREEN,
	BLUE,
	COLOR_COUNT
};

int main() {
	for (int i = RED; i < COLOR_COUNT; i++) {
		switch(i) {
		case RED:
			cout <<"RED";
			break;
		case GREEN:
			cout <<"GREEN";
			break;
		case BLUE:
			cout <<"BLUE";
			break;
		}
		cout <<"=" <<i <<endl;
	}

	return 0;
} ///:~
