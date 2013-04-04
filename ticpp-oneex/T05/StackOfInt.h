//: T05:StackOfInt.h
#ifndef __STACKOFINT_H__
#define __STACKOFINT_H__

class StackOfInt {
	struct StackImp; // Class declaration only
	StackImp* imp;
public:
	void initialize();
	void cleanup();
	int push(int data);
	int pop(int* pdata);
	int count();
};
#endif // __STACKOFINT_H__ 
///:~
