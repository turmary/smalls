//: T12:T12-23.cpp
//给Dog及DogHouse类加入一个static int和一个普通int数据成员

#include "../require.h"
#include <string>
#include <iostream>
using namespace std;

class Dog {
	string nm;
	int refcount;
	int id;
	static int objcount;
	Dog(const string& name): nm(name), refcount(1) {
		id = ++objcount;
		cout << "Creating: " << *this << endl;
	}
	// Prevent assignment:
	Dog& operator=(const Dog& rv);
public:
	// Dogs can only be created on the heap:
	static Dog* make(const string& name) {
		return new Dog(name);
	}
	Dog(const Dog& d) 
		: nm(d.nm + "_cc"), refcount(1) {
		id = ++objcount;
		cout << "Copying : " 
				 << *this << endl;
	}
	~Dog() { 
		cout << "Deleting: " << *this << endl;
	}
	void attach() { 
		++refcount;
		cout << "Attach  : " << *this << endl;
	}
	void detach() {
		require(refcount != 0);
		cout << "Detach  : " << *this << endl;
		// Destroy object if no one is using it:
		if(--refcount == 0) delete this;
	}
	// Conditionally copy this Dog.
	// Call before modifying the Dog, assign
	// resulting pointer to your Dog*.
	Dog* unalias() {
		cout << "Unalias : " << *this << endl;
		// Don't duplicate if not aliased:
		if(refcount == 1) return this;
		--refcount;
		// Use copy-constructor to duplicate:
		return new Dog(*this);
	}
	void rename(const string& newName) {
		nm = newName;
		cout << "Rename  : " << *this << endl;
	}
	friend ostream&
	operator<<(ostream& os, const Dog& d) {
		return os << "[Dog " << d.nm <<" " << d.id << ", ref# = " 
			<< d.refcount << "]";
	}
};

int Dog::objcount = 0;

class DogHouse {
	Dog* p;
	string houseName;
	int id;
	static int objcount;
public:
	DogHouse(Dog* dog, const string& house): p(dog), houseName(house) {
		id = ++objcount;
		cout << "Created : "<< *this << endl;
	}
	DogHouse(const DogHouse& dh)
		: p(dh.p),
		  houseName("cc_" + dh.houseName)
	{
		id = ++objcount;
		p->attach();
		cout << "Copied  : "
				 << *this << endl;
	}
	DogHouse& operator=(const DogHouse& dh) {
		// Check for self-assignment:
		if(&dh != this) {
			houseName = dh.houseName + "_as";
			// Clean up what you're using first:
			p->detach();
			p = dh.p; // Like copy-constructor
			p->attach();
		}
		cout << "oper  = : "
				 << *this << endl;
		return *this;
	}
	// Decrement refcount, conditionally destroy
	~DogHouse() {
		cout << "Deleting: " 
				 << *this << endl;
		p->detach(); 
	}
	void renameHouse(const string& newName) {
		houseName = newName;
	}
	void unalias() { p = p->unalias(); }
	// Copy-on-write. Anytime you modify the 
	// contents of the pointer you must 
	// first unalias it:
	void renameDog(const string& newName) {
		unalias();
		p->rename(newName);
	}
	// ... or when you allow someone else access:
	Dog* getDog() {
		unalias();
		return p; 
	}
	friend ostream&
	operator<<(ostream& os, const DogHouse& dh) {
		return os << "[DogHouse " << dh.houseName 
			   << " " << dh.id
			   << "] "
			   <<"contains " << *dh.p;
	}
};

int DogHouse::objcount = 0;

int main() {
	DogHouse 
		fidos(Dog::make("Fido"), "fidos"),
		spots(Dog::make("Spot"), "spots");
	cout <<endl;

	cout << "Entering copy-construction" << endl;
	DogHouse bobs(fidos);
	cout <<endl;

	cout << "After copy-constructing bobs" << endl;
	cout << "fidos:" << fidos << endl;
	cout << "spots:" << spots << endl;
	cout << "bobs:" << bobs << endl;
	cout <<endl;

	cout << "Entering spots = fidos" << endl;
	spots = fidos;
	cout <<endl;

	cout << "After spots = fidos" << endl;
	cout << "spots:" << spots << endl;
	cout << "Entering self-assignment" << endl;
	bobs = bobs;
	cout <<endl;

	cout << "After self-assignment" << endl;
	cout << "bobs:" << bobs << endl;
	cout <<endl;

	// Comment out the following lines:
	cout << "Entering rename(\"Bob\")" << endl;
	bobs.getDog()->rename("Bob");
	cout << "After rename(\"Bob\")" << endl;

	return 0;
} ///:~
