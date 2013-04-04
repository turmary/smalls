//: T08:T08-18.cpp
//修改ConstTemporary.cpp
//观察每一行产生的错误信息

class X {};

X f() { return X(); } // Return by value

// in passing argument 1 of 'void g1(X&)'
void g1(X&) {} // Pass by non-const reference
void g2(const X&) {} // Pass by const reference

int main() {
	// 从X类型临时变量到X的最常量引用的无效初使化
	// invalid initialization of non-const reference of
	// type 'X&' from a temporary of type 'X'
	// Error: const temporary created by f():
	g1(f());
	// OK: g2 takes a const reference:
	g2(f());
} ///:~
