//: T03:T03-07.cpp
// replace all the string arg2 from in arg1 file
// to string arg3 to, output to standard output.
// ignore from's case
#include <fstream>
#include <iostream>
#include <string>
#include "../require.h"
#include "T03Util.h"
using namespace std;

int main(int argc, char* argv[]) {
	requireArgs(argc, 3, "Usage: replace <file> <from> <to>");

	// See if input file exists
	ifstream inf(argv[1]);
	if(!inf) {
		cerr << "error opening file: " << argv[1] << endl;
		exit(EXIT_FAILURE);
	}

	string from(argv[2]);
	string to(argv[3]);

	// Read input file line by line
	// then do replacing.
	string line;
	ostream& outf = cout;
	while(getline(inf, line)) {
		ireplaceAll(line, from, to);
		outf <<line << endl;	// Output line replaced
	}
	exit(EXIT_SUCCESS);
} ///:~
