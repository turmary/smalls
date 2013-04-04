//: T15:T15-01.cpp
// Create a simple "shape" hierarchy
#include <iostream>
using namespace std;

class Shape {
public:
	Shape() {
		cout <<__FUNCTION__ <<"()" <<endl;
	}
	~Shape() {
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
	Circle c;
	Square s;
	Triangle t;
	Shape* ptrs[] = {&c, &s, &t};
	int i;

	Shape sh;

	for (i = 0; i < sizeof ptrs / sizeof ptrs[0]; i++) {
		// ptrs[i]->draw();
		ShapeOperation(*ptrs[i]);
	}

	cin.get();
	return 0;
} ///:~
