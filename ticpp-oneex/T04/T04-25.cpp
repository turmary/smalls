//: T04:T04-25.cpp
//修改T04-24.cpp
//使用成员函数形式

#include <iostream>
using namespace std;

struct Link {
	int val;
	Link* next;

	int Create(int size);
	int Print(void);
	int Cleanup(Link* next);
};

int Link::Create(int size) {
	int count = 1;
	Link* h = this;
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

int Link::Print(void) {
	Link* h = this;
	while (h != NULL) {
		cout <<"val = " <<h->val
		     <<"\tpointer = " <<h->next
		     <<endl;
		h = h->next;
	}
	return 0;
}

int Link::Cleanup(Link* p) {
	if (p != NULL) {
		Cleanup(p->next);
		cout <<"deleting Link Node " <<p <<endl;
		delete p;
	}
	return 0;
}

int main() {
	Link* h = new Link;
	h->next = h;

	h->Create(10);
	h->Print();
	h->Cleanup(h);
	return 0;
}
///:~
