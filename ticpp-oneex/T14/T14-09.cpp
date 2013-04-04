//: T14:T14-09.cpp
// StringVector
// try push_back a void* to StringVector
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StringVector: vector<void*> {
public:
	bool push_back(string* s) {
		vector<void*>::push_back(
			reinterpret_cast<void*>(s)
		);
	}
	
	string* operator[] (int i) {
		return reinterpret_cast<string*>(
			vector<void*>::operator[](i)
		);
	}
};

int main() {
	StringVector sv;
	string s1("hello");
	string s2("world");

	sv.push_back(&s1);
	sv.push_back(&s2);

	cout <<*sv[0] <<' ' <<*sv[1] <<endl;


	void* vp = &s1;
	//! sv.push_back(vp);
} ///:~
