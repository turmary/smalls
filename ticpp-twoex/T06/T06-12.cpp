//: T06:T06-12.cpp
// Create a program that, given an integer on the command line,
// creates a “factorial table” of all the factorials up to 
// and including the number on the command line.
// To do this, write a generator to fill a vector<int>,
// and then use partial_sum( ) with a standard function object.
#include <cstdint>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../require.h"
#include "PrintSequence.h"
#include "Generators.h"
using namespace std;

int main(int argc, char* argv[]) {
	requireArgs(argc, 1, "usage: T06-12 <a-integer>");
	int n = atoi(argv[1]);

	vector<uint64_t> s;
	vector<uint64_t> p;

	generate_n(back_inserter(s), n, SkipGen(1, 1));

	partial_sum(s.begin(), s.end(), back_inserter(p), multiplies<uint64_t>());

	print(p.begin(), p.end(), "POWERS:", "\n");
	return 0;
} ///:~
