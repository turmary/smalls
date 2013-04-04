//: T03:VarFunc.h
// 可变参数的函数集
#ifndef __VARFUNC_H__
#define __VARFUNC_H__

#include <cstdarg>

void void_vfunc(int argc, ...);
char char_vfunc(int argc, ...);
int int_vfunc(int argc, ...);
float float_vfunc(int argc, ...);

#endif //__VARFUNC_H__ ///:~
