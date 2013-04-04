//: T12:T12-01.cpp
//创建一个简单的带有++运算符重载的类

#include <iostream>
#include <string>
using namespace std;

class Simple {
	int i;

public:
	Simple(int i = 0): i(i){
	}

	// for ++*this;
	Simple& operator ++(void) {
		++i;
		return *this;
	}

        // for (*this) ++;
	const Simple operator++ (int) {
		int r = i++;
                return Simple(r);
	}

	// for --*this;
	Simple& operator --(void) {
		--i;
		return *this;
	}

        // for (*this) --;
	const Simple operator-- (int) {
		int r = i--;
                return Simple(r);
	}

	const Simple operator- (void) {
		return Simple(-i);
	}

#if 0
        const Simple operator+ (const Simple& s) const {
                return Simple(i + s.i);
        }

	const Simple operator- (const Simple& s) const {
		return Simple(i - s.i);
	}
#else
	friend const Simple operator+ (const Simple& l, const Simple& r);
	friend const Simple operator- (const Simple& l, const Simple& r);
#endif

        void print(const string& s) const {
                cout <<s <<"= " <<i <<endl;
        }

        void print(ostream& os) {
		os <<i <<endl;
        }

	friend ostream& operator<<(ostream& os, const Simple&);
};

ostream& operator<<(ostream& os, const Simple& s) {
	os << s.i;
	return os;
}

const Simple operator+ (const Simple& l, const Simple& r) {
	return Simple(l.i + r.i);
}

const Simple operator- (const Simple& l, const Simple& r) {
	return Simple(l.i - r.i);
}

int main(void) {
	Simple s;
	Simple i;

	s++.print("s++");
	(++i).print("++i");

        Simple a = s + i;
        cout <<"a= ";
        a.print(cout);

	a--;

	(a + 4 - 3).print("a + 4 - 3");
	cout <<"a + 4 = " <<a + 4 <<endl;

	cout <<"-a= " <<(-a) <<endl;

	//3++;
	//--2;
	return 0;
} ///:~
