//: T13:T13-11.cpp
// Overload class space new/delete

#include <cstdio>
#include <cstdlib>
#include <new>
using namespace std;

void* operator new(size_t sz) {
	printf("global operator new: %d Bytes\n", sz);
	void* m = malloc(sz);
	if(!m) puts("out of memory");
	return m;
}

void operator delete(void* m) {
	puts("global operator delete");
	free(m);
}

#if 1
void* operator new[](size_t sz) {
	printf("global operator new array: %d Bytes\n", sz);
	void* m = malloc(sz);
	if(!m) puts("out of memory");
	return m;
}

void operator delete[](void* m) {
	puts("global operator delete array");
	free(m);
}
#endif

class S {
	int i[100];
public:
	S() { puts("S::S()"); }
	~S() { puts("S::~S()"); }
};

class Widget {
	enum { sz = 10 };
	int i[sz];
public:
	Widget() { putchar('*'); }
	~Widget() { putchar('~'); }
	void* operator new(size_t sz) {
		printf("Widget::new: %d bytes\n", sz);
		return ::new char[sz];
	}
	void operator delete(void* p) {
		printf("Widget::delete\n");
		::delete []p;
	}
#if 0
	void* operator new[](size_t sz) {
		printf("Widget::new[]: %d bytes\n", sz);
		return ::new char[sz];
	}
	void operator delete[](void* p) {
		printf("Widget::delete[]\n");
		::delete []p;
	}
#endif
};

int main() {
	puts("creating & destroying an int");
	int* p = new int(47);
	delete p;
	puts("creating & destroying int[4]");
	int* p2 = new int[4];
	delete []p2;
	puts("creating & destroying an s");
	S* s = new S;
	delete s;
	puts("creating & destroying S[3]");
	S* sa = new S[3];
	delete []sa;

	printf("new Widget\n");
	Widget* w = new Widget;
	printf("\ndelete Widget\n");
	delete w;
	printf("\nnew Widget[25]\n");
	Widget* wa = new Widget[25];
	printf("\ndelete []Widget\n");
	printf("########### %d ##########\n", *(reinterpret_cast<int*>(wa) - 1));
	delete []wa;

	delete new Widget;
} ///:~
