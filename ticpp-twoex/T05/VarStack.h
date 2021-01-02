//: T05:VarStack.h
#ifndef __VARSTACK_H__
#define __VARSTACK_H__
#include <memory>
#include <iostream>
#include <cstring>
#include "../require.h"

template<class T, template<class U, class R /*= std::allocator<U>*/ > class _imp>
class Stack {
	// Default constructor performs object
	// initialization for each element in array:
	_imp<T, std::allocator<T> > stack;

public:
	Stack() { }

	// Copy-constructor copies object into array:
	void push(const T& x) {
		stack.push_back(x);
	}

	T& peek() { return stack.back(); }

	// Object still exists when you pop it;
	// it just isn't available anymore:
	T pop() {
		require(stack.size() != 0, "Too many pop()s");

		T t = stack.back();
		stack.pop_back();
		return t;
	}
};

#endif//__VARSTACK_H__
///:~
