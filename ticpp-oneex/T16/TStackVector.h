//: T16:TStackVector.h
// Modify TStack2.h so that it uses a Standard C++ Library
// vector as its underlying implementation. Make sure that
// you don't change the interface, so that TStack2Test.cpp
// works unchanged.
#ifndef __TSTACK_VECTOR_H__
#define __TSTACK_VECTOR_H__

#include <vector>
using namespace std;

template<class T> class Stack {
	vector<T*> vt;
	typedef typename vector<T*>::reverse_iterator vt_it_t;
public:
	Stack() {}
	~Stack();

	void push(T* dat) {
		vt.push_back(dat);
	}

	T* peek() const {
		return vt? vt.back(): 0;
	}

	T* pop();

	// Nested iterator class:
	class iterator; 	// Declaration required
	friend class iterator; // Make it a friend
	class iterator {	// Now define it
		const Stack<T>& st;
		vt_it_t p;
	public:
		// Copy-constructor:
		iterator(const iterator& tl) : st(tl.st), p(tl.p) {
		}
		iterator(const Stack<T>& tl) :
		  st(tl),
		  p(const_cast<Stack<T>&>(tl).vt.rbegin()) {
		}
		// The end sentinel iterator:
		iterator(const Stack<T>& tl, bool) :
		  st(tl),
		  p(const_cast<Stack<T>&>(tl).vt.rend()) {
		}
		// operator++ returns boolean indicating end:
		bool operator++() {
			if (p == st.vt.rend()) {
				return false;
			}
			p++;
			return true;
		}
		bool operator++(int) { return operator++(); }
		T* current() const {
			if (p == st.vt.rend()) {
				return 0;
			}
			return *p;
		}
		// Pointer dereference operator:
		T* operator->() const { 
			return current(); 
		}
		T* operator*() const { return current(); }
		// bool conversion for conditional test:
		operator bool() const { return p != st.vt.rend(); }
		// Comparison to test for end:
		bool operator== (const iterator& ir) const {
			return p == ir.p;
		}
		bool operator!= (const iterator& ir) const {
			return p != ir.p;
		}
	};
	iterator begin() const {
		return iterator(*this); 
	}
	iterator end() const {
		return iterator(*this, true);
	}
};

template<class T> Stack<T>::~Stack() {
	while(vt.size()) {
		delete vt.back();
		vt.pop_back();
	}
}

template<class T> T* Stack<T>::pop() {
	if (vt.empty()) return 0;

	T* result = vt.back();
	vt.pop_back();

	return result;
}

#endif//__TSTACK_VECTOR_H__
///:~
