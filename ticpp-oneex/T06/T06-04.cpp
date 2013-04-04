//: T06:T06-04.cpp
//验证goto跳出循环时
//析构仍然被调用

#include <iostream>
using namespace std;

struct first {
	~first() {
		cout <<__FUNCTION__ <<"()" <<endl;
	}
};

int main() {
	int i;
	for (i = 0; i < 10; i++) { ; }
	for (int i = 0; i < 10; i++) {
		first fir;

		if (i > 5) {
			cout <<"i = " <<i <<endl;
			goto l_exit;
		}
	}
l_exit:
	return 0;
} ///:~
