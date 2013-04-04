//: T15:T15-07.cpp

#include <iostream>
#include <vector>
using namespace std;

class Rodent {
public:
	virtual int action(void) = 0;
	virtual ~Rodent() {
		cout <<"~Rodent" <<endl;
	}
};

class Mouse: public Rodent {
public:
	virtual int action(void) {
		cout <<"Mouse action" <<endl;
		return 0;
	}
	~Mouse() {
		cout <<"~~Mouse" <<endl;
	}
};

class Gerbil: public Rodent {
public:
	virtual int action(void) {
		cout <<"Gerbil action" <<endl;
		return 0;
	}
	~Gerbil() {
		cout <<"~~Gerbil" <<endl;
	}
};

class Hamster: public Rodent {
public:
	virtual int action(void) {
		cout <<"Hamster action" <<endl;
		return 0;
	}
	~Hamster() {
		cout <<"~~Hamster" <<endl;
	}
};

class BlueHamster: public Hamster {
public:
	virtual int action(void) {
		cout <<"BlueHamster action" <<endl;
		return 0;
	}
	~BlueHamster() {
		cout <<"~~~BlueHamster" <<endl;
	}
};

int main(int, char* []) {
	cout <<"Enter main()" <<endl;

	vector<Rodent*> pr;
	vector<Rodent*>::iterator it;

	pr.push_back(new Mouse());
	pr.push_back(new Gerbil());
	pr.push_back(new Hamster());
	pr.push_back(new BlueHamster());

	for (it = pr.begin(); it != pr.end(); it++) {
		(*it)->action();
	}

	for (it = pr.begin(); it != pr.end(); it++) {
		delete *it;
	}

	cout <<"Exit main()" <<endl;
	return 0;
} ///:~
