//: T06:T06-02.cpp
// Using transform() and toupper() (in <cctype>),
// write a single function call that will convert a string to
// all uppercase letters.
#include <iostream>
#include <algorithm>
#include <cctype>
#include "../require.h"
using namespace std;

class UpperGenerator {
public:
	char operator() (char c) {
		return toupper(c);
	}
};

int main(int argc, const char* argv[]) {
	string s = "hello world!";
	cout <<s <<endl;
	transform(s.begin(), s.end(), s.begin(), UpperGenerator());
	cout <<s <<endl;
	return 0;
}
///:~
