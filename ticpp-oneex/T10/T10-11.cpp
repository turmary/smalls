//: T10:T10-11.cpp
//创建一个类包含一个int变量
//

#include "T10-10.h"
#include <iostream>
using namespace std;

int set_abc_1(int i) {
	return abc = i;
}

int get_abc_1(void) {
	return abc;
}

extern Simple s;

int main() {
	auto int i;
	register int j;

	i = 5;
	j = 3;
	cout <<"i = " <<i <<endl;
	cout <<"j = " <<j <<endl;

	set_abc_0(18);
	set_abc_1(32);
	cout <<"abc(0) = " <<get_abc_0() <<endl;
	cout <<"abc(1) = " <<get_abc_1() <<endl;

	s.print();

	s.set_inner(5);
	s.print();

	output_int(25);

	return 0;
} ///:~
