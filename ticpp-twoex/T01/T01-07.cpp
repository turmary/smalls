//: T01:T01-07.cpp
// proven all object throw by exception will be destroyed properly.
#include <cstdio>
#include <cstddef>
#include <exception>
#include <stdexcept>
#include <iostream>
using namespace std;

void terminator() {
	cout << "I'll be back!" << endl;
	exit(0);
}

void (*old_terminate)() = set_terminate(terminator);

class out_of_range_ex: public out_of_range {
public:
	out_of_range_ex(): out_of_range("Origin")  {
		fprintf(stderr, "%s(origin)\n", __func__);
	}
	out_of_range_ex(const out_of_range_ex& o): out_of_range("Copy") {
		fprintf(stderr, "%s(copy)\n", __func__);
	}
	~out_of_range_ex() throw() {
		fprintf(stderr, "%s()\n", __func__);
	}

private:
	static void* operator new(size_t siz) {
		void* p = ::operator new(siz);
		cout << "Allocating out_of_range_ex object on the heap "
		     << "at address " << p << endl;
		return p;
	}

	static void operator delete(void* p) {
		cout << "Deleting out_of_range_ex object at address "
		     << p << endl;
		::operator delete(p);
	}
};

class Botch {
public:
	void f() {
		cout << "Botch::f()" << endl;
		throw out_of_range_ex();
	}
	~Botch() {}
};

int main() {
	try {
		Botch b;
		b.f();
	// } catch (out_of_range_ex e) {
/*
Botch::f()
out_of_range_ex(origin)
out_of_range_ex(copy)
Catched a object *Copy*
~out_of_range_ex()
~out_of_range_ex()
*/
	} catch (out_of_range_ex& e) {
/*
Botch::f()
out_of_range_ex(origin)
Catched a object *Origin*
~out_of_range_ex()
*/
		fprintf(stderr, "Catched a object *%s*\n", e.what());
	}
} ///:~
