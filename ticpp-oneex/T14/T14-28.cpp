//: T14:T14-28.cpp
// Operator new for arrays
// with memory leak check
#include <vector>
#include <cstring>
#include <new> // Size_t definition
#include <iostream>
#include <algorithm>
using namespace std;
#define trace cout

class Widget {
	enum { sz = 10 };
	int i[sz];
	static vector<Widget*> wv;
	friend class MemoryChecker;
public:
	Widget() {
		trace << "*";
		memset(i, 0, sizeof i);
	}

	~Widget() {
		trace << "~";
		for (int j = 0; j < sz; j++) {
			if (i[j] != 0) {
				cout <<"***error***" <<endl;
				return;
			}
		}
	}

	void* operator new(size_t sz) {
		trace << "Widget::new: "
			<< sz << " bytes" << endl;

		Widget* w = reinterpret_cast<Widget*>(::new char[sz]);
		wv.push_back(w);
		return w;
	}

	void operator delete(void* p) {
		trace << "Widget::delete" << endl;
		::delete [](char*)p;

		Widget* w = reinterpret_cast<Widget*>(p);
		wv.erase(find(wv.begin(), wv.end(), w));
	}

	void* operator new[](size_t sz) {
		trace << "Widget::new[]: "
			<< sz << " bytes" << endl;

		Widget* w = reinterpret_cast<Widget*>(::new char[sz]);
		wv.push_back(w);

		trace << "\t at " <<w <<endl;
		return w;
	}

	void operator delete[](void* p) {
		trace << "Widget::delete[] at " <<p << endl;
		::delete [](char*)p;

		Widget* w = reinterpret_cast<Widget*>(p);
		wv.erase(find(wv.begin(), wv.end(), w));
	}
};

vector<Widget*> Widget::wv;

class MemoryChecker {
	static bool show(Widget* p) {
		trace << "Widget object undelete in " <<p <<endl;
		return true;
	}
public:
	~MemoryChecker() {
		if (Widget::wv.empty()) {
			return;
		}

		for_each(Widget::wv.begin(), Widget::wv.end(), show);
	}
};

MemoryChecker GlobalMemChecker;

class XXX: public Widget {
	enum { sz = 15 };
	int ax[sz];
public:
	XXX() {
		for (int i = 0; i < sz; i++) {
			ax[i] = i;
		}
	}
	~XXX() {
		for (int i = 0; i < sz; i++) {
			if (ax[i] != i) {
				cout <<"~YYY()***error***";
				return;
			}
		}
	}
};

int main() {
	trace << "new Widget" << endl;
	XXX* w = new XXX;
	trace << "\ndelete Widget" << endl;
	delete w;

	trace << "\nnew Widget[25]" << endl;
	XXX* wa = new XXX[25];
	trace << "\ndelete []Widget" << endl;
	delete []wa;

	XXX* wx = new XXX[2];
	trace << "\nnew Widget[2] at " <<wx <<endl;
	// delete []wx;

	return 0;
} ///:~
