//: T01:T01-11.cpp
// class hierachy inner to outer, Motor -> Car -> Garage
// Motor throw a exception
#include <iostream>
#include <string>
using namespace std;

class Garage {
public:
	struct Car {
		struct Motor {
			Motor() {
				throw "a Motor fault";
			}
		};
		Motor motor;

		Car()/* : motor() */ {}
	};
	Car car;

	Garage() try {
	} catch (const char* e) {
		throw string(e) + "(converted)";
	}
};

int main(void) {
	try {
		Garage g;
	} catch (string& e) {
		cerr <<"Catched exception::: " <<e <<endl;
	}
} ///:~
