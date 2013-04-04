//: T08:T08-19.cpp
//创建一个包含const和非const float成员的类

#include <iostream>
using namespace std;

class One {
	const float cf;
	float f;

public:
	One(float f1 = 0.0f, float f2 = 0.0f);
	int output(void);
};

One::One(float f1, float f2): cf(f1), f(f2) { }

int One::output(void) {
	cout <<"cf = " <<cf <<endl;
	cout <<"f = " <<f <<endl;
	return 0;
}

class MyString {
	// mutable string s;
	string s;

public:
	MyString(string as = ""): s(as){ }
	void print(void) {
		cout <<"s = " <<s <<endl;
		return;
	}

	void setString(const string& as) const {
		((MyString*)this)->s = as;
		((MyString*)this)->print();
		return;
	}
};

int main() {
	One one(35.24f, 32.0f);
	one.output();

	MyString m = string("Hello World!");
	m.print();

	m.setString("good");
	m.print();

	const MyString cm = string("For Const!");
	cm.setString("for change const");
	// cm.print();

	return 0;
} ///:~
