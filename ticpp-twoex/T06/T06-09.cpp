//: T06:T06-09.cpp
// Write a program that takes an integer as a command line argument
// and finds all of its factors.
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include "../require.h"
#include "PrintSequence.h"
#include "Generators.h"
using namespace std;

vector<int> find_factors(int n) {
	vector<int> s;
	generate_n(back_inserter(s), n - 2, SkipGen(2, 1));

	vector<int> v;
	remove_copy_if(s.begin(), s.end(),
	               back_inserter(v),
	               bind1st(modulus<int>(), n)
	              );
	return v;
}

int main(int argc, const char* argv[]) {
	requireArgs(argc, 1, "usage: T06-09 <a-integer>");
	int i = atoi(argv[1]);

	vector<int> s = find_factors(i);
	print(s.begin(), s.end());

	return 0;
}
///:~

