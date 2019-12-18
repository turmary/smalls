//: T01:T01-04.cpp
// main function catch any exception
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <csignal>
using namespace std;

void sig_handler(int nr) {
	fprintf(stderr, "%s(%d) +++\n", __func__, nr);
	return;
}

int throw_exception(void) {
	fprintf(stderr, "%s() +++\n", __func__);
	throw out_of_range("from throw_exception()");
	fprintf(stderr, "%s() ---\n", __func__);
	return 0;
}

int main(int argc, char* argv[]) {
	signal(SIGFPE, sig_handler);
	try {
		/*
		 * division by zero will send a signal SIGFPE,
		 * will not throw exception in MinGW.
		 */
		/*
		int b = 0;
		int a = 3 / b;
		*/
		throw_exception();
	} catch (...) {
		fprintf(stderr, "There is some excpetion catched!!!\n");
	}
	return 0;
}
