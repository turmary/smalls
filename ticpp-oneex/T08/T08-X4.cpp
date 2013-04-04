//: T08:T08-04.cpp
//在头文件中创建一个const定义
//并在两个.cpp文件中使用它

#include "cnsthdr.h"
#include <iostream>
using namespace std;

extern const int xxx_handler = 255;

int hello(void) {
	cout <<"cnst_integer_val = " <<cnst_integer_val <<endl;
	return 0;
} ///:~
