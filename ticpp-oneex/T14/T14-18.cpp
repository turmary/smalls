//: T14:T14-18.cpp
// The protected keyword
#include <iostream>
using namespace std;

class Base {
	int i;
protected:
	int read() const { return i; }
	void set(int ii) { i = ii; }
public:
	Base(int ii = 0) : i(ii) {}
	int value(int m) const { return m*i; }
};

class Derived : protected Base {
	int j;
public:
	Derived(int jj = 0) : j(jj) {}
	void change(int x) { set(x); }
	int read() const { return Base::read(); }
	int read_v() const { return Base::value(2); }
}; 

int main() {
	Derived d;
	d.change(10);
	cout <<"Derived r= " <<d.read() <<endl;
	cout <<"Derived rv= " <<d.read_v() <<endl;
} ///:~
