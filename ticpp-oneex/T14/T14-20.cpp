//: T14:T14-20.cpp
// The protected keyword
#include <iostream>
using namespace std;

class SpaceShip {
	int i;
	friend int funcxx(SpaceShip*);
	int fly(void) { cout <<"fly(" <<i <<")" <<endl; }
public:
	SpaceShip(int ii = 0): i(ii) { }
};

class Shuttle: public SpaceShip {
	int load(void) { cout <<"load()" <<endl; }
public:
	Shuttle(int j = 2): SpaceShip(j) { }
};

int funcxx(SpaceShip* s) {
	s->fly();
	//! s->load();
	return 0;
}

int main(int argc, char* argv[]) {
	Shuttle* sh = new Shuttle;
	SpaceShip* ss = new SpaceShip;

	funcxx(sh);
	delete sh;

	funcxx(ss);
	delete ss;
} ///:~
