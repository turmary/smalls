//: T16:T16-19.cpp
// Turn ObjContainer in NestedSmartPointer.cpp from
// Chapter 12 into a template. Test it with two different
// classes.
#include <iostream>
#include <vector>
#include "../require.h"
using namespace std;

class Obj {
	static int i, j;
public:
	void f() { cout <<i++ <<endl; }
	void g() { cout <<j++ <<endl; }
};

// Static member definitions:
int Obj::i = 47;
int Obj::j = 11;

class oj {
	static int x;
public:
	void h() { cout <<x++ <<endl; }
};

int oj::x = 2;

// Container:
template<class T>
class ObjContainer {
	vector<T*> a;
public:
	void add(T* obj) {
		a.push_back(obj);
	}

	class SmartPointer;
	friend class SmartPointer;

	// Function to produce a smart pointer that 
	// points to the beginning of the ObjContainer:
	SmartPointer begin() { 
		return SmartPointer(*this);
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
			if(index >= oc.a.size() - 1) {
				return false;
			}
			if(oc.a[++index] == 0) {
				return false;
			}
			return true;
		}
		bool operator++(int) { // Postfix
			return operator++(); // Use prefix version
		}
		T* operator->() const {
			require(oc.a[index] != 0, "Zero value "
				"returned by SmartPointer::operator->()");
			return oc.a[index];
		}
	};
};

int main(int argc, char* argv[]) {
{
	const int sz = 10;
	Obj o[sz];
	ObjContainer<Obj> oc;
	for(int i = 0; i < sz; i++) {
		oc.add(&o[i]); // Fill it up
	}

	ObjContainer<Obj>::SmartPointer sp = oc.begin();
	do {
		sp->f(); // Pointer dereference operator call
		sp->g();
	} while(++sp);
}

{
	const int sz = 10;
	oj o[sz];
	ObjContainer<oj> oc;
	for(int i = 0; i < sz; i++) {
		oc.add(&o[i]); // Fill it up
	}

	ObjContainer<oj>::SmartPointer sp = oc.begin();
	do {
		sp->h(); // Pointer dereference operator call
	} while(++sp);
}
} ///:~
