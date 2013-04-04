//: T03:T03-06.cpp
// 使用不同类型运行YouPets2.cpp

#include <iostream>
using namespace std;

#define TTYPE double
TTYPE dog, cat, bird, fish;

void f(int pet) {
	cout << "pet id number: " << pet << endl;
}

int main() {
	TTYPE i, j, k;
	cout << "f(): " << (long)&f << endl;
	cout << "dog: " << (long)&dog << endl;
	cout << "cat: " << (long)&cat << endl;
	cout << "bird: " << (long)&bird << endl;
	cout << "fish: " << (long)&fish << endl;
	cout << "i: " << (long)&i << endl;
	cout << "j: " << (long)&j << endl;
	cout << "k: " << (long)&k << endl;
} ///:~
