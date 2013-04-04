//: T16:T16-02.cpp
// Create a simple "shape" hierarchy
// use TStack2.h
#include <iostream>
#include "TStack2.h"
using namespace std;

class Shape {
public:
	Shape() {
		cout <<__FUNCTION__ <<"()" <<endl;
	}
	virtual ~Shape() {
		cout <<__FUNCTION__ <<"()" <<endl;
	}
#if 0
	virtual int draw() = 0;
#else
	virtual int draw() {
		cout <<"Shape Drawing ~~~~~~" <<endl;
	}
#endif
};

class Circle: public Shape {
public:
	Circle() {
		cout <<__FUNCTION__ <<"()" <<endl;
	}
	~Circle() {
		cout <<__FUNCTION__ <<"()" <<endl;
	}
	virtual int draw() {
		cout <<"Circle Drawing !!!!!!" <<endl;
		return 0;
	}
};

class Square: public Shape {
public:
	Square() {
		cout <<__FUNCTION__ <<"()" <<endl;
	}
	~Square() {
		cout <<__FUNCTION__ <<"()" <<endl;
	}
	virtual int draw() {
		cout <<"Square Drawing @@@@@@" <<endl;
		return 0;
	}
};

class Triangle: public Shape {
public:
	Triangle() {
		cout <<__FUNCTION__ <<"()" <<endl;
	}
	~Triangle() {
		cout <<__FUNCTION__ <<"()" <<endl;
	}
	virtual int draw() {
		cout <<"Triangle Drawing ######" <<endl;
		return 0;
	}
};

//int ShapeOperation(Shape s) {
int ShapeOperation(Shape& s) {
	s.draw();
	return 0;
}

int main(int argc, char* argv[]) {
	Stack<Shape> sc;

	sc.push(new Circle);
	sc.push(new Square);
	sc.push(new Triangle);

	Stack<Shape>::iterator i;

	for (i = sc.begin(); i != sc.end(); i++) {
		// ptrs[i]->draw();
		ShapeOperation(**i);
	}

	return 0;
} ///:~
