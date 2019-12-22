//: T02:T02-03.cpp
// Test class Rational
//{L} ../TestSuite/Test T02-04
#include <iostream>
#include <string>
#include <sstream>
#include "Rational.h"
#include "../TestSuite/Test.h"
using namespace std;

class RationalTest : public TestSuite::Test {
public:
	RationalTest() {}
	void run() {
		testFunctions();
		testExceptions();
	}
	void testFunctions() {
		Rational ra(2, 6);
		Rational rb(1, 3);
		Rational rc(0, 5);
		Rational rd;

		test_(-ra == Rational(-1, 3));
		test_(ra + rb == Rational(2, 3));
		test_(ra - rb == rd);
		test_(ra * rb == Rational(1, 9));
		test_(ra / rb == Rational(1, 1));

		test_(ra == rb);
		test_(rc == rd);

		Rational re;
		stringstream ss("4/5");

		ss >> re;
		test_(re == Rational(4, 5));

		stringstream ss1("4 / 5");
		ss1 >> re;
		test_(re == Rational(4, 5));

		stringstream ss2("4/ 5");
		ss2 >> re;
		test_(re == Rational(4, 5));

		stringstream ss3("4 /5");
		ss3 >> re;
		test_(re == Rational(4, 5));

		stringstream st;
		re = Rational(4, 7);
		st << re;
		test_(st.str() == string("4/7"));

		ra = Rational(1, 3);
		ra += rb;
		test_(ra == Rational(2, 3));

		re = Rational(4, 5);
		ra -= re;
		test_(ra == Rational(-2, 15));

		ra = Rational(1, 3);
		ra *= rb;
		test_(ra == Rational(1, 9));

		ra /= rb;
		test_(ra == Rational(1, 3));

		test_(ra < Rational(1, 1));
		test_(ra > Rational(1, 9));
		test_(ra <= Rational(1, 1));
		test_(ra >= Rational(1, 3));
		test_(ra != Rational(1, 9));
	}
	void testExceptions() {
		try {
			Rational(1, 0);
			fail_("No exception when create Rational(1, 0)");
		} catch(invalid_argument& e) {
			cerr <<"Catched exception *" <<e.what() <<"*" <<endl;
			succeed_();
		}
		try {
			Rational rz(0, 2);
			Rational rx(1, 2);
			rx /= rz;
			fail_("No exception when [1/2] /= [0/2]");
		} catch(overflow_error& e) {
			cerr <<"Catched exception *" <<e.what() <<"*" <<endl;
			succeed_();
		}
		try {
			Rational rz(0, 2);
			Rational rx(1, 2);
			const Rational& rr = rx / rz;
			fail_("No exception when [1/2] / [0/2]");
		} catch(overflow_error& e) {
			cerr <<"Catched exception *" <<e.what() <<"*" <<endl;
			succeed_();
		}
		try {
			stringstream ss("XXX");
			Rational rx;
			ss >> rx;
			fail_("No exception when \"XXX\" >> Rational");
		} catch(ios_base::failure& e) {
			cerr <<"Catched exception *" <<e.what() <<"*" <<endl;
			succeed_();
		}
		try {
			stringstream ss("0/0");
			Rational rx;
			ss >> rx;
			fail_("No exception when \"XXX\" >> Rational");
		} catch(ios_base::failure& e) {
			cerr <<"Catched exception *" <<e.what() <<"*" <<endl;
			succeed_();
		}
	}
};

int main() {
	RationalTest test;
	test.run();
	return test.report();
}
///:~
