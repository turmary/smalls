//: T14:T14-02.cpp
// composition & inherit
#include <iostream>
using namespace std;

class A {
public:
	A () { cout <<" create A" <<endl; }
};

class B {
public:
	B () { cout <<" create B" <<endl; }
};

class C: A {
	B b;
};

int main() {
	C c;
} ///:~
