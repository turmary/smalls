//: T12:T12-27.cpp
//¸øNestedSmartPointer.cpp
//¼ÓÈëoperator->*
#include <iostream>
#include <vector>
#include "../require.h"
using namespace std;

class Obj {
	static int i, j;
public:
	void f() { cout << i++ << ' '; }
	void g() { cout << j++ << ' '; }
};

// Static member definitions:
int Obj::i = 47;
int Obj::j = 11;

// Container:
class ObjContainer {
	vector<Obj*> a;
public:
	void add(Obj* obj) { a.push_back(obj); }
	class SmartPointer;
	friend class SmartPointer;
	// Function to produce a smart pointer that 
	// points to the beginning of the ObjContainer:
	SmartPointer begin() { 
		return SmartPointer(*this);
	}
	int count;
	typedef int ObjContainer::* PTR;
	int& operator->*(PTR p) {
		return this->*p;
	}

	class SmartPointer {
		ObjContainer& oc;
		unsigned int index;
	public:
		SmartPointer(ObjContainer& objc) : oc(objc) {
			index = 0;
		}
		// Return value indicates end of list:
		bool operator++() { // Prefix
			if(index >= oc.a.size()) return false;
			if(oc.a[++index] == 0) return false;
			return true;
		}
		bool operator++(int) { // Postfix
			return operator++(); // Use prefix version
		}
		Obj* operator->() const {
			require(oc.a[index] != 0, "Zero value "
				"returned by SmartPointer::operator->()");
			return oc.a[index];
		}
	};
};

int main() {
	const int sz = 10;
	Obj o[sz];
	ObjContainer oc;

	ObjContainer::PTR p = &ObjContainer::count;
	oc ->* p = 25;
	cout << oc ->* p <<endl <<endl;

	for(int i = 0; i < sz; i++)
		oc.add(&o[i]); // Fill it up
	ObjContainer::SmartPointer sp = oc.begin();
	do {
		sp->f(); // Pointer dereference operator call
		sp->g();
	} while(++sp);

	return 0;
} ///:~
