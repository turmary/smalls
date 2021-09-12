//: T06:T06-05.cpp
// Write a “sentence anagram generator” that takes a sentence
// as a command-line argument and produces all possible permutations of
// the words in the sentence.
// (It leaves the words alone and just moves them around.)
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <unistd.h>
#include "../require.h"
using namespace std;

int main(int argc, const char* argv[]) {
	if (argc < 2) {
		cout <<"usage: T06-05 <a-sentense-to-permutation>" <<endl;
		return 1;
	}

	vector<string> vs;

	int i;
	for (i = 1; i < argc; i++) {
		vs.push_back(string(argv[i]));
	}

	unsigned long nf = 1;
	for (i = 2; i <= vs.size(); i++) {
		nf *= i;
	}

	for (i = 0; i < nf; i++) {
		copy(vs.begin(), vs.end() - 1, ostream_iterator<string>(cout, " "));
		cout <<*(vs.end() - 1) <<endl;
		if (! next_permutation(vs.begin(), vs.end())) {
			// break;
		}
	}

	return 0;
}
///:~

