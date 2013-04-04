//: T03:T03-15.cpp
//创建一个含有两个string对象
//和一个int对象的struct

#include <iostream>
using namespace std;

typedef struct ssi{
	string sa;
	string sb;
	int i;
}SSI;

int main() {
	SSI a;

	a.sa = "hello";
	a.sb = "world";
	a.i = 5;

	cout <<a.sa <<" " <<a.sb <<" " <<a.i <<endl;

	SSI* pa = &a;
	pa->sa = "new1";
	pa->sb = "new2";
	pa->i = 7;

	cout <<pa->sa <<" " <<pa->sb <<" " <<pa->i <<endl;

	return 0;
} ///:~
