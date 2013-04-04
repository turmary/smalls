// tary, 15:31 2011-6-29
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[]) {
	int a, b, c;

	a = 10;
	b = 1;
	c = 0;

	try {
		throw 0x12345678;
		c = a / b;
	} catch (int e) {
		cout <<"0x" <<hex <<setw(8) <<e <<endl;
	}

	return c;
}
