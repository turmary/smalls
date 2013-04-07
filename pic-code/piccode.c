#include <stdio.h>

int global_data = 0;

int func_with_arg(int a1) {
	return global_data = a1;
}

int _start() {
	func_with_arg(1);
	return 0;
}
