//: T03:T03-05.cpp
// 计算两表达式的值

#include <iostream>
using namespace std;

int main(int, char* []) {
	cout <<"Enter main()" <<endl;

	int	A = 0,
		X = 1,
		Y = 2,
		Z = 3;

	A = X + Y - 2 / 2 + Z;
	cout <<"first expression result " <<A <<endl;

	A = X + (Y - 2) / (2 + Z);
	cout <<"second expression result " <<A <<endl;

	cout <<"Exit main()" <<endl;
	return 0;
} ///:~
