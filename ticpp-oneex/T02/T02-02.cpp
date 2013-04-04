//: T02:T02-02.cpp
// 输入半径
// 计算圆面积

#include <iostream> // Stream declarations
using namespace std;

const double pi = 3.1416;

int main(int, char* []) {
	double r;

	cout <<"radius?";
	cin >>r;

	cout <<"area of the circle" <<endl
	  <<(pi * r * r) <<endl;

	return 0;
} ///:~
