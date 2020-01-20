//: T04:T04-01.cpp
// Open a file by creating an ifstream object.
// Make an ostringstream object and read the entire contents into
// the ostringstream using the rdbuf( ) member function.
// Extract a string copy of the underlying buffer and
// capitalize every character in the file using
// the Standard C toupper( ) macro defined in <cctype>.
// Write the result out to a new file.
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include "../require.h"
using namespace std;

int main(int argc, const char* argv[]) {
	requireArgs(argc, 1, "T04-01 <file>");

	ifstream inf(argv[1], ios::in | ios::binary);
	assure(inf, argv[1]);

	ostringstream oss;
	oss << inf.rdbuf();

	string s(oss.str());
	for (size_t i = 0; i < s.size(); i++) {
		s[i] = toupper(s[i]);
	}

	string on(argv[1]);
	on.append(".new");
	ofstream of(on.c_str(), ios::binary);
	of << s;
	return 0;
}
///:~
