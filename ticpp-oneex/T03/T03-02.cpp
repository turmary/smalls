//: T03:T03-02.cpp
// 编程使用两重for循环和%去寻找和输出质数

#include <iostream>
using namespace std;

const int n = 100;

int main(int, char* []) {
	cout <<"Enter main()" <<endl;

	for (int i = 2; i < n; i++) {
		int j = 0;

		for (j = 2; j * j < i; j++) {
			if (i % j == 0) {
				break;
			}
		}
		if (j * j > i) {
			cout <<i <<'\t';
		}
	}

	cout <<endl;
	cout <<"Exit main()" <<endl;
	return 0;
} ///:~
