//: T03:T03-09.cpp
//{L} T03Util
// Filter to view html tags and it's content.
#include <cassert>
#include <cmath>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include "T03Util.h"
#include "../require.h"
using namespace std;

string& stripPairs(const string& tag, string& cont) {
	static string lastCont;
	static string lastTag;

	lastCont = cont;
	cont = "";

	if (tag[1] == '/') {
		if (tag.substr(2, tag.size() - 3) == lastTag) {
			cout <<lastTag <<" : *" <<lastCont <<"*" <<endl;
		}
	} else {
		lastTag = tag.substr(1, tag.size() - 2);
	}
	return lastTag;
}

string& stripHTMLTags(string& s) {
	// {t}
	static string curTag, curCont;
	size_t lastPos = 0;

	static bool inTag = false;
	bool done = false;

	while (!done) {
		if (inTag) {
			// The previous line started an HTML tag
			// but didn't finish. Must search for '>'.
			size_t rightPos = s.find('>');
			if (rightPos != string::npos) {
				// {t}
				curTag += s.substr(0, rightPos + 1);
				stripPairs(curTag, curCont);
				lastPos = 0;

				inTag = false;
				s.erase(0, rightPos + 1);
			} else {
				curTag += s;	// {t}

				done = true;
				s.erase();
			}
		} else {
			// Look for start of tag:
			size_t leftPos = s.find('<');
			if (leftPos != string::npos) {
				curCont += s.substr(lastPos, leftPos - lastPos); // {t}

				// See if tag close is in this line:
				size_t rightPos = s.find('>');
				if (rightPos == string::npos) {
					curTag = s.substr(leftPos); // {t}

					inTag = done = true;
					s.erase(leftPos);
				} else {
					// {t}
					curTag = s.substr(leftPos, rightPos - leftPos + 1);
					lastPos = leftPos;
					stripPairs(curTag, curCont);

					s.erase(leftPos, rightPos - leftPos + 1);
				}
			} else {
				curCont += s.substr(lastPos); // {t}

				done = true;
			}
		}
	}
	// Remove all special HTML characters
	replaceAll(s, "&lt;", "<");
	replaceAll(s, "&gt;", ">");
	replaceAll(s, "&amp;", "&");
	replaceAll(s, "&nbsp;", " ");
	// Etc...
	return s;
}

int main(int argc, char* argv[]) {
	requireArgs(argc, 1, "usage: T03-09 <InputFile>");

	ifstream in(argv[1]);
	assure(in, argv[1]);

	string s;
	while (getline(in, s)) {
		if (!stripHTMLTags(s).empty()) {
			// cout <<s << endl;
		}
	}
} ///:~
