//: T08:T08-06.cpp
//创建一个string的const数组
//然后尝试修改数组中的某个值

#include <iostream>
#include <string>
using namespace std;

const long * clp;
long const * lcp;

int fchange(const int h) {
	// h *= 2;
	return h;
}

int fref(float f) {
	const float& rf = f;
	cout <<"rf = " <<rf <<endl;
	return 0;
}

int main() {
	const string s[] = {
		string("hello"),
		string("world"),
		string("!"),
	};

	(string)s[0] = "h";

	cout <<s[0] <<endl;

	long la[] = {1, 3, 5, 7, 9};

	// clp[0] = 24;

	for (clp = la; clp < la + 5; clp ++) {
		cout <<*clp <<" ";
	}
	cout <<endl;

	for (clp--; clp >= la; clp--) {
		cout <<*clp <<" ";
	}
	cout <<endl;

	double da[] = {1.1, 2.1, 3.0, 4.1, 5.2};
	double* const dpc = da;

	dpc[0] = 12.4;
	// dpc++;
	cout <<"dpc[0] = " <<dpc[0] <<endl;

	double const* const dcpc = da;
	//dcpc ++;
	//dcpc[0] = 1.732;
	cout <<"dcpc[0] = " <<dcpc[0] <<endl;

	char* sp = "hello world!";
	//sp[0] = 'A';
	cout <<sp <<endl;

	fchange(5);

	fref(3.24);

	return 0;
} ///:~
