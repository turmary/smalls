//: T06:T06-10.cpp
// Write a program that takes a command-line argument as
// the name of a text file.
// Open this file and read it a word at a time (hint: use >>).
// Store each word into a vector<string>.
// Force all the words to lowercase,
// sort them,
// remove all the duplicates,
// and print the results.
#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "../require.h"
#include "PrintSequence.h"
using namespace std;

char cpp_tolower (char c) {
	return tolower(c);
}

void lower_case(string& s) {
	transform(s.begin(), s.end(), s.begin(), ptr_fun(cpp_tolower));
}

class StringRemoveDup {
	string lastString;
public:
	bool operator() (string s) {
		bool r = (s == lastString);
		lastString = s;
		return r;
	}
};

int main(int argc, char* argv[]) {
	requireArgs(argc, 1, "usage: T06-10 <a-text-file-name>");

	vector<string> words;
	ifstream in(argv[1]);

	string word;
	while (in >> word) {
		words.push_back(word);
	}

	for_each(words.begin(), words.end(), ptr_fun(lower_case));

	stable_sort(words.begin(), words.end());

	vector<string> words2;
	remove_copy_if(words.begin(), words.end(), back_inserter(words2),
	               StringRemoveDup());

	print(words2.begin(), words2.end(), "THE WORDS", "\n");
	return 0;
} ///:~
