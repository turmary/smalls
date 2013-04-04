//: T16:T16-22.cpp
// Inherit a class StringVector from vector<void*> and
// redefine the push_back() and operator[] member
// functions to accept and product only string* (and
// perform the proper casting). Now create a template that
// will automatically make a container class to do the same
// thing for pointers to any type. This technique is often
// used to reduce code bloat from too many template
// instantiations.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StringVector: public vector<void*> {
public:
	void push_back(string* s) {
		vector::push_back(static_cast<void*>(s));
	}
	string* operator[] (int index) {
		return static_cast<string*>(vector::operator[](index));
	}
};

template<class T>
class Vector: public vector<void*> {
public:
	void push_back(T* s) {
		vector::push_back(static_cast<void*>(s));
	}
	T* operator[] (int index) {
		return static_cast<T*>(vector::operator[](index));
	}
};

int main(int argc, char* argv[]) {
	Vector<string> sv;

	sv.push_back(new string("hello"));
	sv.push_back(new string("world"));
	sv.push_back(new string("my"));
	sv.push_back(new string("name"));
	sv.push_back(new string("is"));
	sv.push_back(new string("tary"));

	cout <<"StringVector as below\n";

	for (int i = 0; i < sv.size(); i++) {
		cout <<*sv[i] <<endl;
		delete sv[i];
	}

	return 0;
}
///:~
