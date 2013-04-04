//: T04:T04-15.cpp
//使用sizeof打印出你的编译器
//所有基本数据类型的长度

#include <iostream>
using namespace std;

#define T_LEN(type) sizeof(type)
#define T_STR(type) "sizeof(" #type ") \t=\t"

int main() {
	cout <<T_STR(unsigned char) <<T_LEN(unsigned char) <<endl;
	cout <<T_STR(signed char) <<T_LEN(signed char) <<endl;
	cout <<T_STR(unsigned short) <<T_LEN(unsigned short) <<endl;
	cout <<T_STR(signed short) <<T_LEN(signed short) <<endl;
	cout <<T_STR(unsigned int) <<T_LEN(unsigned int) <<endl;
	cout <<T_STR(signed int) <<T_LEN(signed int) <<endl;
	cout <<T_STR(unsigned long) <<T_LEN(unsigned long) <<endl;
	cout <<T_STR(signed long) <<T_LEN(signed long) <<endl;
	cout <<T_STR(unsigned long long) <<T_LEN(unsigned long long) <<endl;
	cout <<T_STR(signed long long) <<T_LEN(signed long long) <<endl;
	cout <<T_STR(float) <<T_LEN(float) <<endl;
	cout <<T_STR(double) <<T_LEN(double) <<endl;
	cout <<T_STR(long double) <<T_LEN(long double) <<endl;
	return 0;
} ///:~
