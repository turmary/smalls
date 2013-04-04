//: T13:T13-15.cpp
// Operator new for arrays
// with memory leak check
#include <vector>
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
	Widget() { trace << "*"; }

	~Widget() { trace << "~"; }

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

int main() {
	trace << "new Widget" << endl;
	Widget* w = new Widget;
	trace << "\ndelete Widget" << endl;
	delete w;

	trace << "\nnew Widget[25]" << endl;
	Widget* wa = new Widget[25];
	trace << "\ndelete []Widget" << endl;
	delete []wa;

	Widget* wx = new Widget[2];
	trace << "\nnew Widget[2] at " <<wx <<endl;
	// delete []wx;
} ///:~
