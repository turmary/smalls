//: T08:T08-18.cpp
//�޸�ConstTemporary.cpp
//�۲�ÿһ�в����Ĵ�����Ϣ

class X {};

X f() { return X(); } // Return by value

// in passing argument 1 of 'void g1(X&)'
void g1(X&) {} // Pass by non-const reference
void g2(const X&) {} // Pass by const reference

int main() {
	// ��X������ʱ������X��������õ���Ч��ʹ��
	// invalid initialization of non-const reference of
	// type 'X&' from a temporary of type 'X'
	// Error: const temporary created by f():
	g1(f());
	// OK: g2 takes a const reference:
	g2(f());
} ///:~
