//: T16:OStack.h
// Modify C15:OStack.h and C15:OStackTest.cpp by
// templatizing class Stack so that it automatically multiply
// inherits from the contained class and from Object. The
// generated Stack should accept and product only pointers
// of the contained type.
#ifndef __OSTACK_H__
#define __OSTACK_H__

class Object {
public:
	virtual ~Object() = 0;
};

// Required definition:
inline Object::~Object() {}

template<class T>
// class Stack: public T, public Object {
class Stack: public T {
	struct Link {
		T* data;
		Link* next;
		Link(T* dat, Link* nxt):
		  data(dat), next(nxt) {
		}
	}* head;

public:
	Stack() : head(0) {
	}

	~Stack(){ 
		while (head) {
			delete pop();
		}
	}

	void push(T* dat) {
		head = new Link(dat, head);
	}

	T* peek() const { 
		return head? head->data: 0;
	}

	T* pop() {
		if (head == 0) {
			return 0;
		}

		T* result = head->data;
		Link* oldHead = head;
		head = head->next;
		delete oldHead;

		return result;
	}
};

#endif//__OSTACK_H__
///:~
