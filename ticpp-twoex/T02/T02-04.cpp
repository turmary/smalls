//: T02:T02-04.cpp
// implement class Rational and pass
// the test.
//{L} ../TestSuite/Test T02-03
#include "Rational.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

Rational::Rational(int num, int denom)
throw (invalid_argument) {
	if (!denom) {
		throw invalid_argument("Rational() denominator is 0");
	}
	this->num	 = num;
	this->denom = denom;
	format();
}

Rational Rational::operator-() const {
	return Rational(-num, denom);
}

Rational operator+(const Rational& left, const Rational& right) {
	return Rational(
		left.num * right.denom + left.denom * right.num,
		left.denom * right.denom
	).format();
}

Rational operator-(const Rational& left, const Rational& right) {
	return Rational(
		left.num * right.denom - left.denom * right.num,
		left.denom * right.denom
	).format();
}

Rational operator*(const Rational& left, const Rational& right) {
	return Rational(
		left.num * right.num,
		left.denom * right.denom
	).format();
}

Rational operator/(const Rational& left, const Rational& right)
throw (overflow_error){
	if (!right.num) {
		throw overflow_error("global Rational operator/ divider by 0");
	}
	return Rational(
		left.num * right.denom,
		left.denom * right.num
	).format();
}

ostream& operator<<(ostream& os, const Rational& r) {
	os <<r.num <<'/' <<r.denom;
	return os;
}

istream& operator>>(istream& is, Rational& r)
throw (ios_base::failure) {
	Rational t;
	char c;

	is >>t.num;
	// fprintf(stderr, "t.num = %d\n", t.num);
	is >> c;
	// fprintf(stderr, "c		 = %d\n", c);
	if (c != '/') {
		throw ios_base::failure("operator>> delimitor not '/'");
		return is;
	}
	is >> t.denom;
	// fprintf(stderr, "t.denom = %d\n", t.denom);
	if (!t.denom) {
		throw ios_base::failure("operator>> denominator is 0");
		return is;
	}
	r = t;
	return is;
}

Rational& Rational::operator+=(const Rational& right) {
	this->num = this->num * right.denom + this->denom * right.num,
	this->denom *= right.denom;
	return this->format();
}

Rational& Rational::operator-=(const Rational& right) {
	this->num = this->num * right.denom - this->denom * right.num,
	this->denom *= right.denom;
	return this->format();
}

Rational& Rational::operator*=(const Rational& right) {
	this->num	 *= right.num;
	this->denom *= right.denom;
	return this->format();
}

Rational& Rational::operator/=(const Rational& right)
throw (overflow_error) {
	if (!right.num) {
		throw overflow_error("Rational operator/ divider by 0");
	}
	this->num	 *= right.denom;
	this->denom *= right.num;
	return this->format();
}

bool operator<(const Rational& lhs, const Rational& rhs) {
	return lhs.num * rhs.denom < lhs.denom * rhs.num;
}

bool operator>(const Rational& lhs, const Rational& rhs) {
	return lhs.num * rhs.denom > lhs.denom * rhs.num;
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
	return lhs.num * rhs.denom <= lhs.denom * rhs.num;
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
	return lhs.num * rhs.denom >= lhs.denom * rhs.num;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
	return lhs.num * rhs.denom == lhs.denom * rhs.num;
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
	return lhs.num * rhs.denom != lhs.denom * rhs.num;
}

int Rational::gcd(int a, int b) {
	if (a < 0) {
		a = -a;
	}
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

Rational& Rational::format() {
	int g;

	if (denom < 0) {
		num	 = -num;
		denom = -denom;
	}
	if ((g = gcd(denom, num)) > 1) {
		num	 /= g;
		denom /= g;
	}
	return *this;
}
///:~
