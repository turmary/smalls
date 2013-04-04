//: T14:T14-29.cpp
// Operator new for Framis
// with memory leak check
#include <new> // Size_t definition
#include <iostream>
#include <cstdlib>
using namespace std;

class Framis {
	enum { sz = 10 };
	char c[sz]; // To take up space, not used
	static unsigned char pool[];
	static bool alloc_map[];
public:
	enum { psize = 15 };  // frami allowed
	Framis() {
		cout << "Framis()\n";
		for (int i = 0; i < sz; i++) {
			c[i] = i;
		}
	}
	~Framis() {
		cout << "~Framis() ... ";
		for (int i = 0; i < sz; i++) {
			if (c[i] != i) {
				cout <<"***error***" <<endl;
				return;
			}
		}
	}
	void* operator new(size_t) throw(bad_alloc);
	void operator delete(void*);
};

unsigned char Framis::pool[psize * sizeof(Framis)];
bool Framis::alloc_map[psize] = {false};

// Size is ignored -- assume a Framis object
void* Framis::operator new(size_t) throw(bad_alloc) {
	for(int i = 0; i < psize; i++)
		if(!alloc_map[i]) {
			cout << "using block " << i << " ... ";
			alloc_map[i] = true; // Mark it used
			return pool + (i * sizeof(Framis));
		}
	cout << "cout of memory" << endl;
	throw bad_alloc();
}

void Framis::operator delete(void* m) {
	if(!m) return; // Check for null pointer
	// Assume it was created in the pool
	// Calculate which block number it is:
	unsigned long block = (unsigned long)m - (unsigned long)pool;
	block /= sizeof(Framis);
	cout << "freeing block " << block << endl;
	// Mark it free:
	alloc_map[block] = false;
}

class YYY: public Framis {
	enum { sz = 10 };
	int ax[sz];
public:
	YYY() {
		for (int i = 0; i < sz; i++) {
			ax[i] = i;
		}
	}
	~YYY() {
		cout <<"~YYY()" <<endl;
		for (int i = 0; i < sz; i++) {
			if (ax[i] != i) {
				cout <<"***error***";
				return;
			}
		}
	}
#if 1
	// there will be error 
	// if the functions like below absense
	void* operator new(size_t sz) {
		return (void*)new char[sz];
	}

	void operator delete(void *m) {
		if (!m) return;
		delete[] (char*)m;
	}
#endif
};


int main() {
	YYY* f[YYY::psize];
	try {
		for(int i = 0; i < YYY::psize; i++)
			f[i] = new YYY;
		new YYY; // Out of memory
	} catch(bad_alloc) {
		cerr << "Out of memory!" << endl;
	}

	delete f[10];
	f[10] = 0;
	// Use released memory:
	YYY* x = new YYY;
	delete x;
	for(int j = 0; j < YYY::psize; j++)
		delete f[j]; // Delete f[10] OK

	return 0;
} ///:~
