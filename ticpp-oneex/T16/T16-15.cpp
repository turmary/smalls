//: T16:T16-15.cpp
// In IterIntStack.cpp modify IntStackIter to give it an
// "end sentinel" constructor, and add operator== and
// operator!=. In main() use an iterator to move through
// the elements of the container until you reach the end
// sentinel.
//{L} fibonacci
#include "fibonacci.h"
#include "../require.h"
#include <iostream>
using namespace std;

class IntStack {
	enum { ssize = 100 };
	int stack[ssize];
	int top;
public:
	IntStack() : top(0) {}
	void push(int i) {
		require(top < ssize, "Too many push()es");
		stack[top++] = i;
	}
	int pop() {
		require(top > 0, "Too many pop()s");
		return stack[--top];
	}
	friend class IntStackIter;
};

// An iterator is like a "smart" pointer:
class IntStackIter {
	IntStack& s;
	int index;

public:
	IntStackIter(IntStack& is) : s(is), index(0) {}
	IntStackIter(IntStack& is, bool) : s(is), index(is.top) {}

	int operator++() {	// Prefix
		require(index < s.top, "iterator moved out of range");
		return s.stack[++index];
	}

	int operator++(int) {	// Postfix
		require(index < s.top, "iterator moved out of range");
		return s.stack[index++];
	}

	bool operator== (const IntStackIter& it) {
		return index == it.index;
	}

	bool operator!= (const IntStackIter& it) {
		return ! operator==(it);
	}
};

int main(int argc, char* argv[]) {
	IntStack is;

	for (int i = 0; i < 20; i++) {
		is.push(fibonacci(i));
	}

	// Traverse with an iterator:
	IntStackIter it(is), ie(is, true);

	for (; !(it == ie);) {
		cout << it++ << endl;
	}

	return 0;
}
///:~
