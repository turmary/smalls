//: T10:T10-10.h
//验证当带有多个静态变量的头文件被多个cpp文件包含时
//不会有名字冲突
#include "T10-10.h"
using namespace std;

int set_abc_0(int i) {
	return abc = i;
}

int get_abc_0(void) {
	return abc;
}

//static Simple s = 2;
Simple s = 2;

//static
int output_int(int i) {
	cout <<__FUNCTION__ <<"(" <<i <<")" <<endl;
	return 0;
}

///:~
