//: T04:T04-12.cpp
// Discover the maximum number of digits of precision
// that your implementation of iostreams will print by repeatedly increasing the value of the argument to precision( )
// when printing a transcendental number such as sqrt(2.0).
#include <cmath>
#include <iostream>
#include <sstream>
#include <fstream>
#include "../require.h"
using namespace std;

int main(int argc, const char* argv[]) {
	size_t i;
	stringstream ss[3];

	for (i = 1; ; i++) {
		ss->str("");
		ss->clear();
		ss->precision(i);
		*ss <<sqrt(2.0);
		// cout <<ss->rdbuf() <<endl;
		if (ss[0].str() == ss[1].str() && ss[1].str() == ss[2].str()) {
			break;
		}
		ss[2].str(ss[1].str());
		ss[1].str(ss[0].str());
	}
	cout <<ss->str() <<endl;
	cout <<"Length = " <<strlen(ss->str().c_str()) - 1 <<endl;
	return 0;
}
///:~
