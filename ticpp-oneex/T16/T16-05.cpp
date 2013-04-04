//: T16:T16-05.cpp
#include <iostream>
#include "../require.h"
using namespace std;

template <typename T>
T fibonacci(int n) {
	const int sz = 100;
	require(n < sz);
	static T f[sz]; // Initialized to zero

	f[0] = f[1] = 1.0001;
	// Scan for unfilled array elements:
	int i;
	for(i = 0; i < sz; i++) {
		if(f[i] == 0)
			break;
	}
	while (i <= n) {
		f[i++] = f[i-1] + f[i-2];
	}
	return f[n];
}

int main(int argc, char* argv[]) {
	for (int i = 0; i < 25; i++) {
		cout <<"[" <<i <<"]=" <<fibonacci<float>(i) <<endl;
	}
	for (int i = 0; i < 25; i++) {
		cout <<"[" <<i <<"]=" <<fibonacci<long>(i) <<endl;
	}
	return 0;
}
///:~
