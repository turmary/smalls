//: T03:T03-08.cpp
// find all palindromes in the specified file，
// with case insensitive.
// Syys
// nAN
// syys
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../require.h"
#include "T03Util.h"
using namespace std;

// 0 -- compare inner istrings
// 1 -- compare between istring & string with override function
// 2 -- compare between istring & string with STL error
#define COMPARE_ISTRING_STRING	1

vector<istring> palins;

#if COMPARE_ISTRING_STRING == 1
namespace std {
inline bool operator==(const istring& lhs, const string& rhs) {
	return lhs.compare(istring(rhs.c_str())) == 0;
}
}
#else
/*
STL errors:

if  find(palins.begin(), palins.end(), sv[i])
not find(palins.begin(), palins.end(), istring(sv[i].c_str()))

/c/msys/MinGW/include/c++/3.4.5/bits/stl_algo.h:231:
	error: no match for 'operator==' in '
		(&__first)->__gnu_cxx::__normal_iterator<_Iterator, _Container>::operator* 
			[with _Iterator = std::istring*, _Container = std::vector<std::istring, std::allocator<std::istring> >]
		() == __val'
							^
							  \
							    \
/c/msys/MinGW/include/c++/3.4.5/bits/stl_algo.h:314:   instantiated from 
	`_InputIterator std::find(_InputIterator, _InputIterator, const _Tp&) 
		[with _InputIterator = __gnu_cxx::__normal_iterator<std::istring*, std::vector<std::istring, std::allocator<std::istring> > >, 
		_Tp = std::basic_string<char, std::char_traits<char>, std::allocator<char> >]'
				^
				 \
				  \
T03-08.cpp:64:   instantiated from here
*/
#endif

int scanline(const string& line) {
	vector<string> sv;

	sv = to_words(line);
	for (size_t i = 0; i < sv.size(); i++) {
		// cout <<sv[i] <<endl;
		if (!is_palindrome(sv[i])) continue;

		// find duplicated
		if (palins.end() != find(palins.begin(), palins.end(), 
			#if COMPARE_ISTRING_STRING
			sv[i]
			#else
			istring(sv[i].c_str())
			#endif
		)) {
			continue;
		}
		palins.push_back(sv[i].c_str());
	}
	return 0;
}

int main(int argc, char* argv[]) {
	requireArgs(argc, 1, "Usage: T03-08 <file>");

	// See if input file exists
	ifstream inf(argv[1]);
	if(!inf) {
		cerr << "error opening file: " << argv[1] << endl;
		exit(EXIT_FAILURE);
	}

	// Read input file line by line
	// then find all palindromes.
	string line;
	while(getline(inf, line)) {
		// cout <<line << endl;
		scanline(line);
	}

	cout <<"### All unique palindromes: ###" <<endl;
	for (size_t i = 0; i < palins.size(); i++) {
		cout <<palins[i] <<endl;
	}
	exit(EXIT_FAILURE);
} ///:~
