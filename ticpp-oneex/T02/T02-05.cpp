//: T02:T02-05.cpp
// 修改Fillvector.cpp
// 使它能从后向前打印各行

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int main(int, char* []) {
	vector<string> v;
	ifstream in("T02-05.cpp");

	string line;
	while (getline(in, line)) {
		v.push_back(line);
	}

	for (int i = v.size() - 1; i >= 0; --i) {
		cout <<setfill('0') <<setw(3);
		cout <<i <<": " <<v[i] <<endl;
	}

	return 0;
} ///:~
