//: T16:OwnerStack.h
// Create a version of OwnerStack.h that uses a Standard
// C++ Library vector as its underlying implementation.
// You may need to look up some of the member functions
// of vector in order to do this (or just look at the <vector>
// header file).
#ifndef __OWNERSTACK_H__
#define __OWNERSTACK_H__

#include <vector>
using namespace std;

template<class T>
class Stack {
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef T const & const_reference;
	typedef unsigned size_type;
	typedef int difference_type;
	vector<pointer> vt;

	bool own;
public:
	Stack(bool own = true) : own(own) {}

	~Stack();

	void push(pointer p) {
		vt.push_back(p);
	}

	pointer peek() const {
		return vt.empty() ? 0 : vt.back(); 
	}

	pointer pop();

	bool owns() const {
		return own;
	}

	void owns(bool newownership) {
		own = newownership;
	}

	// Auto-type conversion: true if not empty:
	operator bool() const {
		return !vt.empty();
	}
};

template<class T> T* Stack<T>::pop() {
	if(vt.empty()) {
		return 0;
	}

	pointer result = vt.back();

	vt.pop_back();
	return result;
}

template<class T> Stack<T>::~Stack() {
	if (!own) {
		return;
	}

	while (!vt.empty()) {
		delete pop();
	}
}

#endif//__OWNERSTACK_H__
///:~
