//: T06:T06-04.cpp
//��֤goto����ѭ��ʱ
//������Ȼ������

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
