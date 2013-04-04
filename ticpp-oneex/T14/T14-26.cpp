//: T14:T14-25.cpp
// Create vector<Rock>
// explain the output you get
#include <vector>
#include <iostream>
using namespace std;

class Rock {
	static int obj_cnt;
	int id;
public:
	Rock() {
		cout <<__func__ <<"(" <<(id = obj_cnt++) <<")" <<endl;
	}
	Rock(const Rock& cr) {
		cout <<__func__ <<"(" <<(id = obj_cnt++) <<")"
			" from Rock(" <<cr.id <<")" << endl;
	}
	~Rock() {
		cout <<__func__ <<"(" <<id <<")" <<endl;
	}
};

int Rock::obj_cnt = 0;

int main() {
	vector<Rock> vr;
	//! vector<Rock&> vrc;

	// vr.insert(vr.begin(), Rock());
	vr.push_back(Rock());
	// vr.insert(vr.begin(), Rock());
	vr.push_back(Rock());

	vector<Rock*> vrp;
	vrp.push_back(new Rock());
	vrp.push_back(new Rock());

	vector<Rock*>::reverse_iterator it;
	for (it = vrp.rbegin(); it != vrp.rend(); it++) {
		delete *it;
	}
	return 0;
} ///:~
