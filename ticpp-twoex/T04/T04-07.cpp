//: T04:T04-07.cpp
// String streams accommodate easy conversions, but they come with a price.
// Write a program that races atoi( ) against the stringstream conversion system
// to see the effect of the overhead involved with stringstream.
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "../require.h"
using namespace std;

int ssatoi (const char * str) {
	stringstream ss(str);
	int i;
	ss >>i;
	return i;
}

int (*xatoi) (const char * str);

int main(int argc, const char* argv[]) {
	int n;

	requireArgs(argc, 2, "T04-07 <a|s> <integer>");

	if (*argv[1] == 'a' || *argv[1] == 'A') {
		xatoi = atoi;
	} else {
		xatoi = ssatoi;
	}

	for (int i = 0; i < 1000000; i++) {
		n = xatoi(argv[2]);
	}
	cout <<n <<endl;
	return 0;
}
///:~
