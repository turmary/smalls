//: T04:T04-02.cpp
// Create a program that opens a file (the first argument on the command line)
// and searches it for any one of a set of words 
// (the remaining arguments on the command line).
// Read the input a line at a time,
// and write out the lines (with line numbers) that match to the new file.
#include <string>
#include <iostream>
#include <sstream>
#include "../require.h"
#include "../T03/T03Util.h"
using namespace std;

int count_words(stringstream& ss,  istream& is, const string& find) {
	string buf;
	int line = 1;

	while (getline(is, buf)) {
		vector<string> vs = to_words(buf);
		for (size_t i = 0; i < vs.size(); i++) {
			if (vs[i] == find) {
				ss <<line <<" : " <<buf <<endl;
				break;
			}
		}
		line++;
	}
	return 0;
}

int main(int argc, const char* argv[]) {
	requireArgs(argc, 2, "T04-02 <file> <word-to-search>");

	ifstream inf(argv[1], ios::in | ios::binary);
	assure(inf, argv[1]);

	stringstream ss;
	count_words(ss, inf, argv[2]);

	string on(argv[1]);
	on.append(".words");
	ofstream of(on.c_str(), ios::binary);
	of << ss.rdbuf();

	return 0;
}
///:~
