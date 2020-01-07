//: T03:T03-12.cpp
// find letter occurence frequencies.
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "../require.h"
using namespace std;

#define CPAIR_GLOBAL_NAMESPACE	1

#if CPAIR_GLOBAL_NAMESPACE == 0
namespace std {
#endif//CPAIR_GLOBAL_NAMESPACE
	struct cpair{
		char c;
		int cnt;
	};

	/*
	 * gcc version 6.3.0 (MinGW.org GCC-6.3.0-1) requires
	 * operator< and cpair in the same namespace
	 */
	bool operator<(const cpair& lhs, const cpair& rhs) {
		return lhs.cnt < rhs.cnt;
	}
#if CPAIR_GLOBAL_NAMESPACE == 0
}
#endif

vector<cpair> cv;
int freqs[128];
#define BEGIN 32
#define END   127

int stat_line(const string& s) {
	for (size_t i = 0; i < s.size(); i++) {
		if (BEGIN <= s[i] && s[i] < END) {
			freqs[(int)s[i]] ++;
		}
	}
	return 0;
}

int main(int argc, char* argv[]) {
	requireArgs(argc, 1, "Usage: T03-12 <file>");

	// See if input file exists
	ifstream inf(argv[1]);
	if(!inf) {
		cerr << "error opening file: " << argv[1] << endl;
		exit(EXIT_FAILURE);
	}

	// Read input file line by line
	// then find all palindromes.
	string line;
	while (getline(inf, line)) {
		stat_line(line);
	}

	cout <<"### Letters frequency: ###" <<endl;
	for (size_t i = BEGIN; i < END; i++) {
		if (!freqs[i]) continue;

		cpair cp = {char(i), freqs[i]};
		cv.push_back(cp);

		/*
		if (i == 0x20) {
			cout <<"Space: ";
		} else {
			cout <<char(i) <<": ";
		}
		cout <<freqs[i] <<endl;
		*/
	}
	sort(cv.begin(), cv.end());

	for (int i = cv.size() - 1; i >= 0; i--) {
		const cpair* cp = &cv[i];

		if (cp->c == 0x20) {
			cout <<"Space: ";
		} else {
			cout <<char(cp->c) <<": ";
		}
		cout <<cp->cnt <<endl;
	}

	exit(EXIT_FAILURE);
}
///:~
