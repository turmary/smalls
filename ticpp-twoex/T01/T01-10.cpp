//: T01:T01-10.cpp
// throw a double exception which not in the specification list
// and recoverable if entered unexpected().
#include <cstdio>
#include <iostream>
#include <stdexcept>
using namespace std;

struct customized_exception {};

void this_unexpected() {
	static bool first = true;
	cerr <<"\n######   unexpected exception thrown";

	if (first) {
		first = false;
		throw 3.14;
	} else {
		throw 4;
	}
}

void exception_spec(int type) throw(char, int, bool, customized_exception, bad_exception) {
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
	case 5:
	case 6:
		throw 3.14;
		break;
	}
	return;
}

int main(int argc, char* argv[]) {
	set_unexpected(this_unexpected);

	for (int i = 0; i < 8; i++) {
		int c;

		fprintf(stderr, "\n>>>>>>   exception_spec(%d)", i);
		try {
			exception_spec(i);
		} catch (char& e) {
			fprintf(stderr,
				"\nThere is char exception *%c* catched!!!", e);
		} catch (int& e) {
			fprintf(stderr,
				"\nThere is int  exception *%d* catched!!!", e);
		} catch (bool& e) {
			cerr <<"\nThere is bool exception *" <<e <<"*";
		} catch (customized_exception& e) {
			fprintf(stderr,
				"\nThere is customized exception ** catched!!!");
		} catch (double& e) {
			fprintf(stderr,
				"\nThere is double exception *%lf* catched!!!", e);
		} catch (bad_exception& e) {
			fprintf(stderr,
				"\nThere is bad exception ** catched!!!");
		}
		cerr <<endl;
	}
	return 0;
} ///:~
