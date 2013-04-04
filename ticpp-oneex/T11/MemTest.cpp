//: C07:MemTest.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Testing the Mem class
//{L} Mem
#include "Mem.h"
#include <cstring>
#include <iostream>
using namespace std;

class MyString {
	Mem* buf;
public:
	MyString();
	MyString(const MyString& s);
	MyString& operator=(const MyString& s);
	MyString(char* str);
	~MyString();
	void concat(char* str);
	void print(ostream& os);
};

MyString::MyString() {	buf = 0; }

MyString::MyString(const MyString& s) {
	buf = 0;	//s.buf;
}

MyString& MyString::operator=(const MyString& s) {
	// buf = s.buf;
};

MyString::MyString(char* str) {
	buf = new Mem(strlen(str) + 1);
	strcpy((char*)buf->pointer(), str);
}

void MyString::concat(char* str) {
	if(!buf) buf = new Mem;
	strcat((char*)buf->pointer(
		buf->msize() + strlen(str) + 1), str);
}

void MyString::print(ostream& os) {
	if(!buf) return;
	os << buf->pointer() << endl;
}

MyString::~MyString() {
	cout <<"~";
	if (buf) {
		cout <<buf->pointer();
		*(buf->pointer()) = '\0';
	}
	cout <<endl;
	delete buf;
}

int main() {
	MyString s("s: My test string");
	s.print(cout);
	s.concat(" some additional stuff");
	s.print(cout);

	MyString s2;
	s2.concat("s2: Using default constructor");
	s2.print(cout);

	s = s2;
	s.print(cout);

	MyString s3(s2);
	s3.print(cout);

	return 0;
} ///:~
