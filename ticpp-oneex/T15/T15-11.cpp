//: T15:T15-11.cpp
// Create an air-traffic control system
#include <vector>
#include <iostream>
using namespace std;

class Aircraft {
public:
	virtual void fly(void) = 0;
};

class Fly1: public Aircraft {
public:
	virtual void fly(void) {
		cout <<__FUNCTION__ <<"(first)" <<endl;
	}
};

class Fly2: public Aircraft {
public:
	virtual void fly(void) {
		cout <<__FUNCTION__ <<"(second)" <<endl;
	}
};

class Tower {
	vector<Aircraft*> vac;
public:
	void add(Aircraft* ap) {
		vac.push_back(ap);
	}
	void StartFly(void) {
		vector<Aircraft*>::iterator it;
		for (it = vac.begin(); it != vac.end(); it++) {
			(*it)->fly();
		}
	}
	~Tower() {
		vector<Aircraft*>::iterator it;
		for (it = vac.begin(); it != vac.end(); it++) {
			delete *it;
		}
	}
};

int main(int argc, char* argv[]) {
	Tower t;

	t.add(new Fly1());
	t.add(new Fly2());
	
	t.StartFly();

	return 0;
} ///:~
