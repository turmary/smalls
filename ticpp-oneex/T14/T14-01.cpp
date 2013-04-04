//: T14:T14-01.cpp
// Public composition and inherit

class Engine {
public:
	void start() const {}
	void rev() const {}
	void stop() const {}
};

class Wheel {
public:
	void inflate(int psi) const {}
};

class Window {
public:
	void rollup() const {}
	void rolldown() const {}
};

class Door {
public:
	Window window;
	void open() const {}
	void close() const {}
};

class Vehicle {
	int id;
public:
	Vehicle(): id(0) {}
	Vehicle(int i): id(i) {}
};

class Car: public Vehicle {
	enum { V_ID = 3, };
public:
	Car(): Vehicle(V_ID) {}
	Engine engine;
	Wheel wheel[4];
	Door left, right; // 2-door
};

int main() {
	Car car;
	car.left.window.rollup();
	car.wheel[0].inflate(72);
} ///:~
