//: T16:VectorStack.h
#ifndef __VECTORSTACK_H__
#define __VECTORSTACK_H__
#include <vector>
#include <iostream>
#include <cstring>
#include "../require.h"

template<class T>
class Stack {
	// Default constructor performs object
	// initialization for each element in array:
	std::vector<T> stack;

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

#endif//__VECTORSTACK_H__
///:~
