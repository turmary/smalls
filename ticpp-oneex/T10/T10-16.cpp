//: T10:T10-16.cpp
//写一个包含第二个头文件的cpp文件

#include "second.h"
#include "NamespaceInt.h"
#include <iostream>
using namespace std;

namespace first = namespace_first;

int call_second(void) {
	using namespace first;
	// using first::first_print;
	// using first::second_print;

	first_print(NULL);
	second_print();

	return 0;
}

namespace Me {
class Us {
	int inner;
public:
	Us(int ii): inner(ii) {
	}

	friend void you(const Us& u);
};

void you(const Us& u) {
	cout <<"Us.inner = " <<u.inner <<endl;
}
}

void arithmetic(void) {
	using namespace Int;
	Integer x;
	x.setSign(positive);
}

int main() {
	//using namespace first;
	//using namespace namespace_second;
	using namespace_second::CFirst;

	CFirst fi;
	first::CFirst fi2;

	first::first_print();
	call_second();
	first::second_print(NULL);

	null_print();

	Me::Us u(3);
	Me::you(u);

	arithmetic();

	//! Integer x;

	return 0;
}

namespace namespace_first {
int first_print(void) {
	cout <<__FUNCTION__ <<"(void)" <<endl;
	return 0;
}

int first_print(int* p) {
	cout <<__FUNCTION__ <<"(int* p)" <<endl;
	return 0;
}

int second_print(void) {
	cout <<__FUNCTION__ <<"(void)" <<endl;
	return 0;
}

int second_print(int* p) {
	cout <<__FUNCTION__ <<"(int* p)" <<endl;
	return 0;
}
}

namespace {
int null_print(void) {
	cout <<__FUNCTION__ <<"(void)" <<endl;
	return 0;
}
}
///:~
