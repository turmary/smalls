//: C13:Counted.cpp {O}
// ����һ��class Counted
// ����static��count��Ա�Ը����͵Ķ������

#include "Counted.h"
#include <iostream>
using namespace std;


int Counted::count = 0;

int Counted::f(void) {
	cout << __func__ << "(): id=" <<id <<endl;
	return id;
}
///:~
