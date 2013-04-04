//: T10:T10-32.cpp
//创建多个Mirror对象,并指定连接顺序

#include "mirror.h"
#include <iostream>
using namespace std;

extern Mirror m2;
Mirror m3(&m2);

int main() {
	cout <<"test() = " <<(m3.test()? "true": "false") <<endl;
	return 0;
}
///:~
