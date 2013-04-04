//: T04:T04-24.cpp
//创建一个struct
//存放int和另一个相同struct实例的指针

#include <iostream>
using namespace std;

struct Link {
	int val;
	Link* next;
};

int LinkCreate(Link* h, int size) {
	int count = 1;
	Link* p = h;

	h->val = count++;
	for (int i = 1; i < size; i++) {
		p = new Link;
		p->val = count++;
		h = h->next = p;
	}
	p->next = NULL;
	return size;
}

int LinkPrint(Link* h) {
	while (h != NULL) {
		cout <<"val = " <<h->val
		     <<"\tpointer = " <<h->next
		     <<endl;
		h = h->next;
	}
	return 0;
}

int LinkCleanup(Link* h) {
#if 0
	while (h != NULL) {
		Link* p = h;
		h = h->next;
		delete p;
	}
#endif
	if (h) {
		LinkCleanup(h->next);
		cout <<"delete Link Node " <<h <<endl;
		delete h;
	}
	return 0;
}

int main() {
	Link* h = new Link;
	LinkCreate(h, 10);
	LinkPrint(h);
	LinkCleanup(h);
	return 0;
}
///:~
