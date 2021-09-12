//: T06:T06-11.cpp
// Write a program that finds all the words that are in
// common between two input files, using set_intersection().
// Change it to show the words that are not in common,
// using set_symmetric_difference().
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "../require.h"
#include "PrintSequence.h"
using namespace std;

int main(int argc, char* argv[]) {
	requireArgs(argc, 2, "usage: T06-11 <first-text-file-name> <second-text-file-name>");

	set<string> words;
	ifstream in(argv[1]);

	string word;
	while (in >> word) {
		words.insert(word);
	}

	ifstream in2(argv[2]);
	set<string> words2;
	while (in2 >> word) {
		words2.insert(word);
	}

	vector<string> words3;
	set_intersection(words.begin(),  words.end(),
			 words2.begin(), words2.end(), back_inserter(words3));
	vector<string> words4;
	set_symmetric_difference(words.begin(),  words.end(),
			         words2.begin(), words2.end(), back_inserter(words4));

	print(words3.begin(), words3.end(), "THE COMMON WORDS", "\n");
	print(words4.begin(), words4.end(), "THE DIFF   WORDS", "\n");
	return 0;
} ///:~
