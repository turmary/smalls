//: T01:T01-01.cpp
// Four methods to handle error or exception.
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cerrno>
#include <csignal>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

int err_return(void) {
	std::printf("This is %s()\n", __func__);
	return -EINVAL;
}

int err_errno(void) {
	std::printf("This is %s()\n", __func__);
	errno = EINVAL;
	return 0;
}

static void sig_handler(int no) {
	std::printf("This is %s(%d)\n", __func__, no);
	// abort();
	return;
}

int err_signal(void) {
	for (int i = 0; i < NSIG; i++) {
		signal(i, sig_handler);
	}
	raise(SIGSEGV);
	std::fprintf(stderr, "This is %s()\n", __func__);
	int b = 0;
	int a = 3 / b;
	return a;
}

int err_catch(void) {
	throw string("Throw from err_catch()");
	std::printf("This is %s()\n", __func__);
	return 0;
}

int main(int argc, char* argv[]) {
	char c;

	if (argc < 2) {
		const char* base_name = argv[0];

		base_name += strlen(argv[0]);
		while (--base_name > argv[0]) {
			if (base_name[-1] == '/' || base_name[-1] == '\\') {
				break;
			}
		}
		printf("Usage: \n\t%s [V,E,S,X]\n", base_name);
		return 1;
	}

	c = toupper(argv[1][0]);

	switch (c) {
	case 'V':
		std::printf("This is error [%d]\n", err_return());
		break;
	case 'E':
		err_errno();
		std::printf("This is error [%s]\n", strerror(errno));
		break;
	case 'S':
		err_signal();		
		break;
	case 'X':
	default:
		try {
			err_catch();
		} catch (string& s) {
			std::printf("%s\n", s.c_str());
		}
		break;
	}
	std::printf("Now program will exit with no exception\n");
	return 0;
} ///:~
