//: T12:T12-14.cpp
//创建一个Bird类

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
using namespace std;

class Bird {
	string s;
	static int i;
	int mi;

public:
	Bird(int mi = 0) :mi(mi) {
		char buf[12];
		s = "Bird #";
		itoa(++i, buf, 10);
		s += buf;
	}

	Bird(const Bird& b) {
		s = b.s;
		mi = b.mi;
		i++;
	}

	Bird& operator= (const Bird& b) {
		s = b.s;
		mi = b.mi;
		return *this;
	}

	const Bird operator+(const Bird& rb) {
		return Bird(mi + rb.mi);
	}

	const Bird operator-(const Bird& rb) {
		return Bird(mi - rb.mi);
	}

	const Bird operator*(const Bird& rb) {
		return Bird(mi * rb.mi);
	}

	const Bird operator/(const Bird& rb) {
		if (rb.mi != 0) {
			return Bird(mi / rb.mi);
		}
		return Bird(INT_MAX);
	}

	friend ostream& operator<<(ostream& os, const Bird& b) {
		os <<"/==Bird=== " <<b.mi <<"===\\" <<endl;
		os <<b.s;
		return os;
	}
};

int Bird::i = 0;

class BirdHouse {
	Bird b;
	Bird* pb;
	Bird& rb;

	int mi;

public:
	BirdHouse(const BirdHouse& bh) :rb(bh.rb){
		*this = bh;
	}

	BirdHouse(const Bird& b1, const Bird& b2, Bird& b3, int mi = 0):
		b(b1), pb(NULL), rb(b3), mi(mi)
	{
		pb = new Bird(b2);
	}

	~BirdHouse(void) {
		if (pb != NULL) {
			delete pb;
		}
	}

	BirdHouse& operator=(const BirdHouse& bh) {
		b = bh.b;
		// cout <<"bh.pb =  " <<bh.pb <<endl;
		if (pb != NULL) {
			delete pb;
		}
		pb = new Bird(*bh.pb);
		rb = bh.rb;
		mi = bh.mi;
		return *this;
	}

	const BirdHouse operator+(const BirdHouse& bh) {
		return BirdHouse(
		  b + bh.b,
		  *pb + *bh.pb,
		  rb,
		  mi + bh.mi
		);
	}

	const BirdHouse operator-(const BirdHouse& bh) {
		return BirdHouse(
		  b - bh.b,
		  *pb - *bh.pb,
		  rb,
		  mi - bh.mi
		);
	}

	const BirdHouse operator*(const BirdHouse& bh) {
		return BirdHouse(
		  b * bh.b,
		  *pb * *bh.pb,
		  rb,
		  mi * bh.mi
		);
	}

	const BirdHouse operator/(const BirdHouse& bh) {
		if (bh.mi != 0) {
			return BirdHouse(
			  b / bh.b,
			  *pb / *bh.pb,
			  rb,
			  mi / bh.mi
			);
		}
		return BirdHouse(
		  b / bh.b,
		  *pb / *bh.pb,
		  rb,
		  INT_MAX
		);
	}

	friend ostream& operator<<(ostream& os, const BirdHouse& bh) {
		os <<"/==BirdHouse===== " <<bh.mi <<"===\\" <<endl;
		os <<bh.b <<endl;
		os <<*bh.pb <<endl;
		os <<bh.rb <<endl;
	}
};

int main() {
	Bird b(1);
	cout <<b <<endl;

	Bird c(3);
	cout <<c <<endl;

	Bird d(b);
	cout <<d <<endl;

	Bird x(5);
	cout <<x <<endl;

	x = c;
	cout <<x <<endl;

	BirdHouse bh(b, d, x, 1);
	BirdHouse bh2(b, c, d, 3);
	BirdHouse bh3(d, c, x, 4);
	cout <<bh <<endl;
	cout <<bh2 <<endl;
	cout <<bh3 <<endl;

	// bh = bh2 = bh3;
	// bh = bh2 + bh3;
	cout <<bh2 + bh3 <<endl;
	cout <<bh2 - bh3 <<endl;
	cout <<bh2 * bh3 <<endl;
	cout <<bh3 / bh2 <<endl;

	return 0;
} ///:~
