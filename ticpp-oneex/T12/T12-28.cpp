//: T12:T12-28.cpp
//创建两个新类Apple和Orange

#include <iostream>
#include <vector>
#include "../require.h"
using namespace std;

class Orange {
public:
	int i;
	Orange(const int i = 0):i(i) {	}
};

class Apple {
	int i;
public:
	explicit Apple(Orange o): i(o.i){ }
	int print(void) {
		cout <<i <<endl;
	}
};

int first_func(Apple a) {
	a.print();
}

class Number {
	int i;
public:
	Number(int ii = 0) : i(ii) {}

	const Number operator+(const Number& n) const {
		return Number(i + n.i);
	}

	friend const Number
		operator-(const Number&, const Number&);

	friend const Number
		operator*(const Number&, const Number&);

	friend void print(const Number&);
};

const Number operator-(const Number& n1, const Number& n2) {
	return Number(n1.i - n2.i);
}

const Number operator*(const Number& n1, const Number& n2) {
	return Number(n1.i * n2.i);
}

void print(const Number& n) {
	cout <<n.i <<endl;
}


class OOrange {};
class Pear {};

class AApple {
public:
	operator OOrange() const { };
	operator Pear() const { };
};

// Overloaded eat():
void eat(OOrange) { };
void eat(Pear) { };

int main() {
	Orange o(5);
	// first_func(o);
	first_func(Apple(o));

	Number a(47), b(11);
	print(a + b);
	print(a + 1);
	// print(1 + a);
	print(a - b);
	print(a - 1);
	print(1 - a);

	print(a * b);
	print(a * 1);
	print(1 * a);

	AApple c;
	eat(Pear(c));
	// Error: Apple -> Orange or Apple -> Pear ???

	return 0;
} ///:~
