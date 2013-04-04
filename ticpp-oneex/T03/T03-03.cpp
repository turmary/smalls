//: T03:T03-03.cpp
//  π”√if∫Õswitch

#include <iostream>
#include <fstream>
using namespace std;

const string fname = string("t03-03.cpp");

int main(int, char* []) {
	// cout <<"Enter main()" <<endl;

	string s;
	ifstream in(fname.c_str());

	while (in >>s) {
		int type;

		if (s == "int") {
			type = 1;
		} else if (s == "{") {
			type = 3;
		} else if (s == "}") {
			type = 4;
		} else if (s == "using") {
			type = 5;
		} else if (s == "///:~") {
			type = 0;
		} else {
			type = 7;
		}
		switch(type) {
		case 0:
			cout <<"program exited" <<endl;
			exit(0);
			break;
		case 1:
			cout <<"typed int" <<endl;
			break;
		case 3:
			cout <<"left brace" <<endl;
			break;
		case 4:
			cout <<"right brace" <<endl;
			break;
		case 5:
			cout <<"using keyword" <<endl;
			break;
		default:
			cout <<'x' <<' ';
			break;
		}
	}

	cout <<endl;
	// cout <<"Exit main()" <<endl;
	return 0;
} ///:~
