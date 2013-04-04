//: T03:T03-26.cpp
//定义int数组并转换成void*

#include <iostream>
using namespace std;

void process_arrays(void* p, int count, unsigned char val) {
	unsigned char* s;

	s = reinterpret_cast<unsigned char*>(p);
	for (int i = 0; i < count; i++) {
		s[i] = val;
	}

	return;	
}

int main() {
	int a[] = {1, 2, 3, 4, 5,};

	process_arrays(static_cast<void*>(a), sizeof a, '1');

	for (int i = 0; i < sizeof a / sizeof a[0]; i++) {
		cout <<"a[" <<i <<"] = " <<hex <<a[i] <<endl;
	}
	cout <<endl;
	
} ///:~
