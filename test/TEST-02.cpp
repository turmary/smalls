#include <iostream>
using namespace std;

int defaultArg(int first, int second = 20) {
	cout <<"first = " <<first <<endl;
	cout <<"second = " <<second <<endl;
	return 0;
}

int main() {
	unsigned char a = 0x0;
	unsigned char b = (unsigned char)~a >> 4;

	cout <<"a = " <<(int)~a <<endl;
	cout <<"b = " <<(int)b <<endl;

	{
	unsigned char a = 0x1;
	unsigned char b = (a << 10) & 0xFF;

	cout <<"a = " <<(int)a <<endl;
	cout <<"b = " <<(int)b <<endl;
	}

	{
	unsigned int a1 = 0x80000000;
	signed int a2 = 0x80000000;

	if (a1 == a2) {
		cout <<"they are same the + result " <<a1 + a2 <<endl;
	}
	}

	defaultArg(2);

	defaultArg(2, 0);
	return 0;
}
