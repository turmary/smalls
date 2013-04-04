//: T10:T10-01.cpp
//创建一个函数,每次调用返回
//第一次调用设置的初值的每个元素,直到-1

#include <iostream>
using namespace std;

int oneFunction(int* ip = 0) {
	static int* sip = 0;

	if (ip != 0) {
		return *(sip = ip);
	}
	if (*sip == -1) {
		return -1;
	}
	return *sip++;
}

int Fibonacci(bool reset = false) {
	static int i0 = 0, i1 = 1;

	if (reset) {
		i0 = 0; i1 = 1;
		return i0;
	}

	int t = i0 + i1;
	i0 = i1;
	i1 = t;

	return i0;
}

class Three {
	static const int SIZE = 20;
	int a[SIZE];

	const int ci;

	static int si;
public:
	Three(int size = 1): ci(size) {
		for (int i = 0; i < SIZE; i++) a[i] = SIZE - i;
		return;
	}

	static int print_si(void) {
		cout <<"si = " <<si <<endl;
		return 0;
	}

	int print(void) {
		for (int i = 0; i < SIZE; i++) {
			cout <<"a[" <<i <<"] = " <<a[i] <<endl;
		}

		cout <<"ci = " <<ci <<endl;
		print_si();
		return 0;
	}

};

int Three::si = 0x200;


int main() {
	int a[] = {1, 3, 5, 8, 2, 9, 11, -1};

	oneFunction(a);

	for (int i = oneFunction(); i != -1; i = oneFunction()) {
		cout <<"i = " <<i <<endl;
	}

	for (int i = 0; i < 20; i++) {
		if (i == 8) {
			cout <<"F(" <<i <<") = " <<Fibonacci(true) <<endl;
		} else {
			cout <<"F(" <<i <<") = " <<Fibonacci() <<endl;
		}
	}

	Three thr;
	thr.print();

	return 0;
} ///:~
