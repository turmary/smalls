//: T16:ValueStack.h
// Modify ValueStack.h so that is dynamically expands as
// you push() more objects and it runs out of space. Change
// ValueStackTest.cpp to test the new functionality.
#ifndef __VALUESTACK_H__
#define __VALUESTACK_H__
#include <iostream>
#include <cstring>
#include "../require.h"

template<class T, int ssize = 10>
class Stack {
	static const int incr = 10;
	// Default constructor performs object
	// initialization for each element in array:
	T* stack;
	int ability;
	int top;

	int increment_space(void) {
		std::cout <<__func__ <<"()" <<std::endl;
		const int tsz = sizeof(T);

		T* st = new T[ability + incr];
		memcpy(st, stack, tsz * ability);
		ability += incr;

		delete []stack;
		stack = st;
	}

public:
	Stack() : top(0), stack(new T[ssize]), ability(ssize) {
	}
	// Copy-constructor copies object into array:
	void push(const T& x) {
		if (top >= ability) {
			increment_space();
		}
		stack[top++] = x;
	}
	T peek() const { return stack[top]; }
	// Object still exists when you pop it; 
	// it just isn't available anymore:
	T pop() {
		require(top > 0, "Too many pop()s");
		return stack[--top];
	}
};

#endif//__VALUESTACK_H__
///:~
