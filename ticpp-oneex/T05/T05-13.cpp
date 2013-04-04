//: T05:T05-13.cpp
//�޸�Handle.cpp�еĽṹCheshire
//���UseHandle���Ƿ����±���

#include "Handle.h"
#include "../require.h"

// Define Handle's implementation:
struct Handle::Cheshire {
	int j;
	int k;
	int i;
};

void Handle::initialize() {
	smile = new Cheshire;
	smile->i = 0;
}

void Handle::cleanup() {
	delete smile;
}

int Handle::read() {
	return smile->i;
}

void Handle::change(int x) {
	smile->i = x;
} ///:~
