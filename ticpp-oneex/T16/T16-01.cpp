//: T16:T16-01.cpp
// Create a OShape hierarchy
#include <iostream>
using namespace std;

class Object {
};

class Shape {
};

class OShape: public Object, public Shape {
};

class Circle: public Shape {
};

class Square: public Shape {
};

class Triangle: public Shape {
};

class OCircle: public OShape, public Circle {
};

class OSquare: public OShape, public Square {
};

class OTriangle: public OShape, public Triangle {
};

int main(int argc, char* argv[]) {
	
	return 0;
} ///:~
