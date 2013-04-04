//: T05:StackOfInt.cpp {O}

#include "StackOfInt.h"
#include <iostream>
using namespace std;

const int STACK_CAPCITY = 100;

struct StackOfInt::StackImp {
	int Stack[STACK_CAPCITY];
	int top;
};

void StackOfInt::initialize() {
	imp = new StackImp;
	imp->top = 0;
}

void StackOfInt::cleanup() {
	delete imp;
}

int StackOfInt::push(int data) {
	if (imp->top >= STACK_CAPCITY) {
		return -1;
	}
	imp->Stack[imp->top++] = data;
	return 0;
}

int StackOfInt::pop(int* pdata) {
	if (imp->top <= 0) {
		return -1;
	}
	*pdata = imp->Stack[--imp->top];
	return 0;
}

int StackOfInt::count() {
	return imp->top;
}
///:~
