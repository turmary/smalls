//: T03:T03-06.cpp
// replace all the string arg2 from in arg1 file
// to string arg3 to, output to standard output.
#include <fstream>
#include <iostream>
#include <string>
#include "../require.h"
#include "T03Util.h"
using namespace std;

// Legacy non-standard C header for mkdir()
#if defined(__WIN32__)
#include <direct.h>
#elif defined(__GNUC__) || defined(__MWERKS__)
#include <sys/stat.h>
#elif defined(__BORLANDC__) || defined(_MSC_VER) \
  || defined(__DMC__)
#include <direct.h>
#else
#error Compiler not supported
#endif

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
		replaceAll(line, from, to);
		outf <<line << endl;	// Output line replaced
	}
	exit(EXIT_SUCCESS);
} ///:~
