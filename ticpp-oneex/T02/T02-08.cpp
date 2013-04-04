//: T02:T02-08.cpp
// 创建一个vector<float>
// 并输入25个浮点数

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int FLOAT_COUNT = 3;	//25;

int main(int argc, char* argv[]) {
	vector<float> vf;

	float f;
	for (int i = 0; i < FLOAT_COUNT; i++) {
		cin >>f;
		vf.push_back(f);
	}

	cout <<"The vector: " <<endl;
	for (int i = 0; i < vf.size(); i++) {
		cout <<setfill('0') <<setw(3) <<i;
		cout <<": " <<vf[i] <<endl;
	}

	return 0;
} ///:~
