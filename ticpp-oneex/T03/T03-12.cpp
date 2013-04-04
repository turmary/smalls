//: T03:T03-12.cpp
// 修改Boolean.cpp, Bitwise.cpp，使用精确的类型
//{L} printBinary

#include "printBinary.h"
#include <iostream>
using namespace std;

int Boolean(void) {
	cout <<__FUNCTION__ <<"()" <<endl;
	int	i = 2,
		j = 5;
	bool	ba = true,
		bb = false;


	cout << "i > j is " << bool(i > j) << endl;
	cout << "i < j is " << bool(i < j) << endl;
	cout << "i >= j is " << bool(i >= j) << endl;
	cout << "i <= j is " << bool(i <= j) << endl;
	cout << "i == j is " << bool(i == j) << endl;
	cout << "i != j is " << bool(i != j) << endl;
	cout << "ba && bb is " << bool(ba && bb) << endl;
	cout << "ba || bb is " << bool(ba || bb) << endl;
	cout << " (i < 10) && (j < 10) is "
	     << bool((i < 10) && (j < 10)) << endl;

	return 0;
}

#define PR(STR, EXPR) \
	cout << STR; printBinary(EXPR); cout << endl;	

int Bitwise(void) {
	cout <<__FUNCTION__ <<"()" <<endl;
	unsigned int getval;
	unsigned char a, b;

	// cin >> getval; a = getval;
	a = 34;
	PR("a in binary: ", a);

	b = 129;
	// cin >> getval; b = getval;
	PR("b in binary: ", b);
	PR("a | b = ", a | b);
	PR("a & b = ", a & b);
	PR("a ^ b = ", a ^ b);
	PR("~a = ", ~a);
	PR("~b = ", ~b);
	// An interesting bit pattern:
	unsigned char c = 0x5A; 
	PR("c in binary: ", c);
	a |= c;
	PR("a |= c; a = ", a);
	b &= c;
	PR("b &= c; b = ", b);
	b ^= a;
	PR("b ^= a; b = ", b);

	return 0;
}

int main() {
	Boolean();
	Bitwise();
} ///:~
