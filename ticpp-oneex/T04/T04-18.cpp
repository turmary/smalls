//: T04:T04-18.cpp
//创建有参数char*的函数
//并申请内存用于拷贝字符内容
//测试这个函数

#include <cstring>
#include <iostream>
using namespace std;

char* func(char* s) {
	char* p;

	p = new char[strlen(s) + 1];
	strcpy(p, s);
	return p;
}

int main() {
	static char s[] = "hello world!";

	char* s1 = func(s);
	cout <<"s1 = " <<s1 <<endl;
	cout <<"&s1 = " <<static_cast<void*>(s1) <<endl;

	char* s2 = func(s1);
	cout <<"s2 = " <<s2 <<endl;
	cout <<"&s2 = " <<static_cast<void*>(s2) <<endl;

	delete s1;
	delete s2;
	return 0;
} ///:~
