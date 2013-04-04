//: T12:T12-18.cpp
//给SmartPointer.cpp和NestedSmartPointer.cpp
//加入操作符--


#include <iostream>
#include <vector>
#include "../require.h"

using namespace std;

class Obj {
	static int i, j;

public:
	void f() const {
		cout << i++ << endl;
	}

	void g() const {
		cout << j++ << endl;
	}
};

// Static member definitions:
int Obj::i = 47;
int Obj::j = 11;

// Container:
class ObjContainer {
	vector<Obj*> a;

public:
	void add(Obj* obj) {
		a.push_back(obj);
	}
	friend class SmartPointer;

	class SmartPointer {
		ObjContainer& oc;
		unsigned int index;

	public:
		SmartPointer(ObjContainer& objc): oc(objc) {
			index = 0;
		}

		bool operator--() {
			if (index >= oc.a.size()) return false;
			if (oc.a[++index] == 0) return false;
			return true;
		}
		
		bool operator--(int) {
			return operator--();
		}

		Obj* operator->() const {
			require(oc.a[index] != 0, "Zero value "
			  "returned by SmartPointer::operator->()");
			return oc.a[index];
		}
	};

	SmartPointer begin() {
		return SmartPointer(*this);
	}
};

class SmartPointer {
	ObjContainer & oc;
	int index;

public:
	SmartPointer(ObjContainer& objc): oc(objc) {
		index = 0;
	}

	// Return value indicates end of list:
	bool operator++ () {    // Prefix
		if (index >= oc.a.size()) {
			return false;
		}
		if (oc.a[++index] == 0) {
			return false;
		}
		return true;
	}

	bool operator++ (int) {	// Postfix
		return operator++ ();	// Use prefix version
	}

	bool operator-- () {
		if (index >= oc.a.size()) {
			return false;
		}
		if (oc.a[++index] == 0) {
			return false;
		}
		return true;
	}
	
	bool operator-- (int) {
		return operator-- ();
	}

	Obj* operator->() const {
		require(oc.a[index] != 0, "Zero value "
		  "returned by SmartPointer::operator->()");
		return oc.a[index];
	}
};

class Fee {
public:
	Fee(void) {
		cout <<string( __FUNCTION__) <<"(void)" <<endl;
	}

	Fee(const Fee& f) {
		cout <<string( __FUNCTION__) <<"(const Fee&)" <<endl;
	}

	Fee& operator= (const Fee& f) {
		cout <<string( __FUNCTION__) <<"(const Fee&)" <<endl;
	}
	//friend Fee& operator= (Fee& lf, const Fee& f);

};

#if 0
Fee& operator= (Fee& lf, const Fee& f) {
		cout <<string( __FUNCTION__) <<"(const Fee&)" <<endl;
		return lf;
	}
}
#endif

class Foo {
public:
	Foo& operator=(const string s /* = "op=call" */) {
		cout <<s <<endl;
	}

	Foo& operator=(const Foo& f) {
		cout <<string(__FUNCTION__) <<"(const Foo& f)" <<endl;
	}
};

int main() {
	const int sz = 10;
	Obj o[sz];
	ObjContainer oc;

	for (int i = 0; i < sz; i++) {
		oc.add(&o[i]);	// Fill it up
	}

	// SmartPointer sp(oc);	// Create an iterator
	ObjContainer::SmartPointer sp = oc.begin();

	do {
		sp->f();	// Pointer dereference operator call
		sp->g();
	} while (sp--);

	Fee f;
	Fee f2(f);
	Fee f3 = f;

	f = f2;

	Foo fo;
	Foo fo1;
	Foo fo2;

	fo1 = fo;
	fo2 = string("hello world");
	return 0;
} ///:~
