//: T01:T01-05.cpp
// Recover from exception and continue the loop
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <csignal>
using namespace std;

struct Recover {
	static int counter;
	int id;

	Recover() {}

	Recover(int id): id(id) {}

	void* operator new(size_t sz) {
		if (++counter == 11)
			throw out_of_range("run out of memory");
		fprintf(stderr, "%3d", counter);
		return ::new Recover(counter);
	}

	static void gc(Recover* obj) {
		if (obj->id) {
			fprintf(stderr, "%3d", obj->id);
			delete obj;
		}
	}
};

int Recover::counter = 0;

int main(int argc, char* argv[]) {
	for (int i = 0; i < 3; i++) {
		int c;

		fprintf(stderr, "\nloop %d", i);
		Recover* robjs[12];
		try {
			fprintf(stderr, "\nnew    Recover object");
			for (c = 0; c < 12; c++) {
				robjs[c] = new Recover;
			}
			fprintf(stderr, "\ndelete Recover object");
			for (int k = 0; k < c; k++) {
				Recover::gc(robjs[k]);
			}
		} catch (out_of_range& e) {
			fprintf(stderr,
				"\nThere is exception *%s* catched!!!", e.what());
			fprintf(stderr, "\ndelete Recover object");
			for (int k = 0; k < c; k++) {
				Recover::gc(robjs[k]);
			}
		}
	}
	fprintf(stderr, "\n");
	return 0;
} ///:~
