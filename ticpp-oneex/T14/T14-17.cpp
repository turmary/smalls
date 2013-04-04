//: T14:T14-17.cpp
// private or protected inheritance
#include <iostream>
#include <iomanip>
using namespace std;

class base {
};

class deriveda: private base {
};

class derivedb: protected base {
};

int func_base(base* b) {
	cout <<hex <<setfill('0');
	cout <<"0x" <<setw(8) <<(unsigned)b <<endl;
	cout <<"0x" <<setw(8) <<0x20 <<endl;
	return 0;
}

int main(int argc, char* argv[]) {
	deriveda a;
	derivedb b;
	base c;

	//func_base(&a);
	//func_base(&b);
	func_base(&c);
} ///:~
