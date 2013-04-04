//: T04:T04-21.cpp
//证明C++自动创建枚举及联和的typedef等价物

#include <iostream>
using namespace std;

enum color {
	RED,
	GREEN,
	BLUE,
};

union storage_t {
	char c[4];
	int i;
	float f;
};

typedef enum attribute{
	R_ATTRIB,
	G_ATTRIB,
	B_ATTRIB,
}attribute;

typedef union storage {
	char c[4];
	int i;
	float f;
}storage;

int main() {
	enum color c1 = BLUE;
	color c2 = BLUE;
	cout <<"color = " <<(c1 == c2) <<endl;
	c1 = c2;

	union storage_t s1;
	s1.c[0] = 1;
	s1.c[1] = 0;
	s1.c[2] = 0;
	s1.c[3] = 0;
	storage_t s2;
	s2.i = 1;
	cout <<"storage = " <<(s1.i == s2.i) <<endl;
	s1 = s2;

	enum attribute a1 = R_ATTRIB;
	attribute a2 = G_ATTRIB;
	cout <<"attribute = " <<(a1 == a2) <<endl;
	a1 = a2;

	union storage st1;
	st1.c[0] = 1;
	st1.c[1] = 0;
	st1.c[2] = 0;
	st1.c[3] = 0;
	storage st2;
	st2.i = 1;
	cout <<"storage2 = " <<(st1.i == st2.i) <<endl;
	st2 = st1;

	return 0;
} ///:~
