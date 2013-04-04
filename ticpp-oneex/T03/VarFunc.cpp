//: T03:VarFunc.cpp {O}
// 可变参数的函数集

#include "VarFunc.h"
#include <iostream>
using namespace std;

#define VFUNC_CONT(rtype) cout <<__FUNCTION__ <<"()" <<endl;	\
	cout <<"\targc=" <<argc <<endl;				\
	cout <<"\treturn type=" <<#rtype <<endl;

void void_vfunc(int argc, ...) {
	VFUNC_CONT(void);
	return;
}

char char_vfunc(int argc, ...) {
	VFUNC_CONT(char);
	return '0';
}

int int_vfunc(int argc, ...) {
	VFUNC_CONT(int);
	return 0;
}

float float_vfunc(int argc, ...) {
	VFUNC_CONT(float);
	return 0.0;
} ///:~
