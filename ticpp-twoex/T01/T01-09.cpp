//: T01:T01-09.cpp
// exception specification include char,int,bool,customized
#include <cstdio>
#include <iostream>
#include <stdexcept>
using namespace std;

struct customized_exception {
};

void exception_spec(int type) throw(char, int, bool, customized_exception) {
	switch (type) {
	case 0:
		throw '0'; break;
	case 1:
		throw 2;   break;
	case 2:
		throw true;break;
	case 3:
	default:
		throw customized_exception();
		break;
	}
	return;
}

int main(int argc, char* argv[]) {
	for (int i = 0; i < 5; i++) {
		int c;

		fprintf(stderr, "\nexception_spec(%d)", i);
		try {
			exception_spec(i);
		} catch (char& e) {
			fprintf(stderr,
				"\nThere is char exception *%c* catched!!!", e);
		} catch (int& e) {
			fprintf(stderr,
				"\nThere is int  exception *%d* catched!!!", e);
		} catch (bool& e) {
			cerr <<"\nThere is bool exception *" <<e <<"*" <<endl;
		} catch (customized_exception& e) {
			fprintf(stderr,
				"\nThere is customized exception ** catched!!!");
		}
	}
	return 0;
} ///:~
