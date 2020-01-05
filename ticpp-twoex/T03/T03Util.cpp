//: T03:T03Util.cpp {O}
#include <cstddef>
#include <algorithm>
#include "T03Util.h"
using namespace std;
using std::size_t;
using std::string;
using std::istring;
using std::tolower;
using std::toupper;

string str_rev(const string& s) {
  string r(s);
  reverse(r.begin(), r.end());
  return r;
}

istring str_rev(const istring& s) {
  istring r(s);
  reverse(r.begin(), r.end());
  return r;
}

bool is_palindrome(const string& s) {
	const string LOWER = "abcdefghijklmnopqrstuvwxyz";
	string r;

	for (size_t i = 0; i < s.size(); i++) {
		char c = tolower(s[i]);
		if (LOWER.find(c) == string::npos) {
			continue;
		}
		r += c;
	}
	if (r.size() > 1UL && r == str_rev(r)) {
		return true;		
	}
	return false;
}

static const string LOWER = "abcdefghijklmnopqrstuvwxyz";
static const string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const string DIGIT = "0123456789";

vector<string> to_words(const string& s) {
	vector<string> sv;
	string letter = LOWER + UPPER + DIGIT;

	for(size_t i = s.find_first_of(letter); i != string::npos;) {
		size_t e = s.find_first_not_of(letter, i);
		sv.push_back(s.substr(i, e - i));
		i = s.find_first_of(letter, e);
	}
	return sv;
}

string& replaceAll(string& context, const string& from,
  const string& to) {
  size_t lookHere = 0;
  size_t foundHere;
  while((foundHere = context.find(from, lookHere))
    != string::npos) {
    context.replace(foundHere, from.size(), to);
    lookHere = foundHere + to.size();
  }
  return context;
}

// case insensitive
std::string& ireplaceAll(std::string& context,
const std::string& from, const std::string& to) {
  string icon  = lowerCase(context);
  string ifrom = lowerCase(from);
  size_t lookHere = 0;
  size_t foundHere;
  while((foundHere = icon.find(ifrom, lookHere)) != string::npos) {
    icon.replace(foundHere, ifrom.size(), to);
    context.replace(foundHere, from.size(), to);
    lookHere = foundHere + to.size();
  }
  return context;
} ///:~
