//: C13:Counted.cpp {O}
// 创建一个class Counted
// 它有static的count成员对该类型的对象计数

#include "Counted.h"
#include <iostream>
using namespace std;


int Counted::count = 0;

int Counted::f(void) {
	cout << __func__ << "(): id=" <<id <<endl;
	return id;
}
///:~
