//: T15:T15-33.cpp
// create a class with data members and virtual function.
// looks at the memory in an object of your class and 
// prints out the various pieces of it.
#include <vector>
#include <iostream>
#include <aux_lib.h>
using namespace std;

class Aircraft {
private:
	int hello;
	int world;

public:
	Aircraft(int h, int w) {
		hello = h;
		world = w;
	}
	virtual void fly(void) {
		cout <<"(base)::" <<__FUNCTION__ <<"()" <<&Aircraft::fly <<endl;
	}
};

class First: public Aircraft {
public:
	First(): Aircraft(1, 0) {
		// cout <<"(first)::" <<__FUNCTION__ <<"()" <<endl;
		// fly();
	}
	virtual void fly(void) {
		cout <<"(first)::" <<__FUNCTION__ <<"()" <<&First::fly <<endl;
	}
};

class Second: public Aircraft {
	int x;
public:
	Second(): Aircraft(3, 2) {
		x = 2;
		// cout <<"(second)::" <<__FUNCTION__ <<"()" <<endl;
		// fly();
	}
	virtual void fly(void) {
		cout <<"(second)::" <<__FUNCTION__ <<"()" <<&Second::fly <<endl;
	}
};

int main(int argc, char* argv[]) {
	Aircraft* p;
	unsigned long* lp;

	p = new Aircraft(5, 4);
	debug_buf("Aircraft", reinterpret_cast<unsigned char*>(p), sizeof(Aircraft));
	lp = * reinterpret_cast<unsigned long**>(p);
	printf("&Aircraft::fly = 0x%.8X\n", *lp);

	p = new First;
	debug_buf("First", reinterpret_cast<unsigned char*>(p), sizeof(First));
	lp = * reinterpret_cast<unsigned long**>(p);
	printf("&First   ::fly = 0x%.8X\n", *lp);

	p = new Second;
	debug_buf("Second", reinterpret_cast<unsigned char*>(p), sizeof(Second));
	lp = * reinterpret_cast<unsigned long**>(p);
	printf("&Second  ::fly = 0x%.8X\n", *lp);

	return 0;
} ///:~
