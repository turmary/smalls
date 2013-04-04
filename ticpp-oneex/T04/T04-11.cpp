//: T04:T04-11.cpp
//条件编译
//分别使用源码和命令行方式定义条件

#include <iostream>
using namespace std;

#define OK_COND

int main() {
#ifdef OK_COND
	cout <<"OK_COND defined!" <<endl;
#else
	cout <<"OK_COND not defined!" <<endl;	
#endif //NDEBUG
	return 0;
} ///:~
