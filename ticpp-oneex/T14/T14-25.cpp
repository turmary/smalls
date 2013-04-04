//: T14:T14-25.cpp
// Modify InheritStack2.cpp 
// to use a vector<string> instead of a stack
#include "../require.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


class CheckedString {
	string s;
	static vector<CheckedString*> vec;
	friend class MemoryChecker;
	friend bool getline(ifstream& ifs, CheckedString& cs);
public:
	CheckedString(): s("") {}
	CheckedString(const char* str)
	  : s(str) 
	{ }
	CheckedString(const CheckedString& ccs)
	  : s(ccs.s)
	{
	}

	CheckedString& operator=(const CheckedString& ccs) {
		s = ccs.s;
		return *this;
	}
	~CheckedString() { }

	void* operator new(size_t sz) {
		CheckedString* p = 
		  reinterpret_cast<CheckedString*>(::new char[sz]);
		vec.push_back(p);
		return (void*)p;
	}

	void operator delete(void* p) {
		::delete [](char*)p;
		CheckedString* cs = (CheckedString*)p;
		vec.erase(find(vec.begin(), vec.end(), cs));
	}

	friend ostream& operator<< (ostream& os, const CheckedString& ccs) {
		os <<ccs.s;
		return os;
	}
	
	void* operator !=(const char* str) {
		return (void*)strcmp(s.c_str(), str);
	}
};

bool getline(ifstream& ifs, CheckedString& cs) {
	return getline(ifs, cs.s);
}

vector<CheckedString*> CheckedString::vec;

class MemoryChecker {
	static bool show(CheckedString* p) {
		cout << "undeleted object at " <<p <<' ' <<*p <<endl;
	}
public:
	~MemoryChecker() {
		if (CheckedString::vec.empty()) {
			return;
		}

		for_each(CheckedString::vec.begin(), 
			CheckedString::vec.end(), 
			show
		);
	}
};

MemoryChecker GlobalMemChecker;

#define string CheckedString

class StringStack {
	vector<string*> stack; // Embed instead of inherit
public:
	void push(string* str) {
		stack.push_back(str);
		// delete str;
	}
	string* peek() const {
		if (stack.empty()) {
			return NULL;
		}
		return stack.back();
	}
	string* pop() {
		if (stack.empty()) {
			return NULL;
		}

		string* r = stack.back();
		stack.pop_back();
		return r;
	}
};

int main() {
	ifstream in("T14-25.cpp");
	assure(in, "T14-25.cpp");
	string line;
	StringStack textlines;
	while(getline(in, line)) {
		textlines.push(new string(line));
	}
	string* s;
	while((s = textlines.pop()) != 0) { // No cast!
		cout <<*s << endl;
		// delete s;
	}
} ///:~
