//: T16:TStackStack.h
// Repeat Exercise 12 using a Standard C++ Library stack
// instead of a vector(you may need to look up information
// about the stack, or hunt through the <stack> header file).
#ifndef __TSTACK_STACK_H__
#define __TSTACK_STACK_H__

#include <stack>
using namespace std;

template<class T> class Stack {
	stack<T*> vt;
public:
	Stack() {}
	~Stack();

	void push(T* dat) {
		vt.push(dat);
	}

	T* peek() const {
		return vt? vt.top(): 0;
	}

	T* pop();

	// Nested iterator class:
	class iterator; 	// Declaration required
	friend class iterator; // Make it a friend
	class iterator {	// Now define it
		const Stack<T>& st;
		bool end;
	public:
		// Copy-constructor:
		iterator(const iterator& tl) : st(tl.st), end(tl.end) {
		}
		iterator(const Stack<T>& tl) :
		  st(tl),
		  end(false) {
		}
		// The end sentinel iterator:
		iterator(const Stack<T>& tl, bool) :
		  st(tl),
		  end(true) {
		}
		// operator++ returns boolean indicating end:
		bool operator++() {
			if (end) {
				return false;
			}
			const_cast<Stack<T>&>(st).vt.pop();
			return end = st.vt.empty();
		}
		bool operator++(int) { return operator++(); }
		T* current() const {
			if (end) {
				return 0;
			}
			return st.vt.top();
		}
		// Pointer dereference operator:
		T* operator->() const {
			return current();
		}
		T* operator*() const { return current(); }
		// bool conversion for conditional test:
		operator bool() const { return end != true; }
		// Comparison to test for end:
		bool operator== (const iterator& ir) const {
			return end == ir.end;
		}
		bool operator!= (const iterator& ir) const {
			return end != ir.end;
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
	while (vt.size()) {
		delete vt.top();
		vt.pop();
	}
}

template<class T> T* Stack<T>::pop() {
	if (vt.empty()) return 0;

	T* result = vt.top();
	vt.pop();

	return result;
}

#endif//__TSTACK_STACK_H__
///:~
