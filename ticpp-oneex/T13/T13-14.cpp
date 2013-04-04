//: T13:T13-14.cpp
// palcement new

#include <cstdio>
#include <cstdlib>
#include <new>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

vector<string> g;

class Widget {
	static vector<string> v;
	static vector<Widget*> vw;
	static int ref_cnt;
private:
	char* new_items(char* p) {
		
	}
	char* delete_items(void* p) {
		
	}
public:
	Widget() { putchar('*'); ref_cnt++; }
	~Widget() {
		putchar('~');
		if (--ref_cnt != 0) {
			return;
		}
		
		vector<string>::iterator it;
		for (it = v.begin(); it != v.end(); it++) {
			cout <<*it <<endl;
		}
	}
	void* operator new(size_t sz, string s) {
		v.push_back(s);
		printf("Widget::new: %d bytes\n", sz);
		return ::new char[sz];
	}
	void operator delete(void* p) {
		printf("Widget::delete\n");
		::delete [](char*)p;
	}
	void* operator new[](size_t sz, string s) {
		v.push_back(s);
		printf("Widget::new[]: %d bytes\n", sz);
		return ::new char[sz];
	}
	void operator delete[](void* p) {
		printf("Widget::delete[]\n");
		::delete [](char*)p;
	}
};

vector<string> Widget::v;
vector<Widget*> Widget::vw;
int Widget::ref_cnt = 0;

int main() {
	printf("new Widget\n");
	stringstream s;
	Widget* w = new(
		(s << __LINE__, string(__FILE__) + ": " + s.str())
	) Widget;
	printf("\ndelete Widget\n");
	delete w;

	printf("\nnew Widget[25]\n");
	Widget* wa = new(
		(s.str(""), s << __LINE__, string(__FILE__) + ": " + s.str())
	) Widget[25];
	printf("\ndelete []Widget\n");
	printf("########### %d ##########\n", *(reinterpret_cast<int*>(wa) - 1));
	delete []wa;

	delete new(string("hello world!")) Widget;
} ///:~
