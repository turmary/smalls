//: T08:T08-01.cpp
//创建三个const int
//用它们的和定义数组的维数

#include <stdio.h>

const int ca = 0x100;
const int cb = 0x40;
const int cc = 0xc0;

const int cd = ca + 0x100;

int main() {
	int a[ca + cb + cc];

	a[0] = 12;
	a[1] = 24;
	a[2] = (int)&ca;

	printf("a[0] = %d\n", a[0]);
	printf("a[1] = %d\n", a[1]);
	printf("a[2] = %d\n", a[2]);

	return 0;
} ///:~
