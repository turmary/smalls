//: T07:T07-03.cpp
//确定你的编译器是怎样生成汇编代码的
//运行实验以观察名字修饰表

#include <iostream>
//using namespace std;

struct Member {
	Member() { cout <<"Member Created!" <<endl; }
	~Member() { cout <<"Member Killed!" <<endl; }
};

struct OnlyOne {
	Member m;

	const char* onlyMember(void);
	int onlyMember(int h);
};

const char* OnlyOne::onlyMember(void) {
	return "onlyMember";
}

int OnlyOne::onlyMember(int h) {
	cout <<"onlyMember(" <<h <<")" <<endl;
	return 0;
}

int _E_(OnlyOne* op) {
	return 0;
}

int main() {
	OnlyOne onlyOne;

	_E_(&onlyOne);	// __Z3_E_P7OnlyOne

	cout <<onlyOne.onlyMember() <<endl;

	int i = onlyOne.onlyMember(5);
	return 0;
} ///:~
