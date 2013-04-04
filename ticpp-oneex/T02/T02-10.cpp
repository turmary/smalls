//: T02:T02-10.cpp
// 创建一个vector<float>
// 求每个元素的平方
// 并生成新的vector<float>

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int FLOAT_COUNT = 3;	//25;

int main(int argc, char* argv[]) {
	float f;

	vector<float> vf1;
	cout <<"vf1?" <<endl;
	for (int i = 0; i < FLOAT_COUNT; i++) {
		cin >>f;
		vf1.push_back(f);
	}

	vector<float> vf;
	for (int i = 0; i < FLOAT_COUNT; i++) {
		f = vf1[i] * vf1[i];
		vf.push_back(f);
	}

	cout <<"The vf1   &   vf2: " <<endl;
	for (int i = 0; i < vf.size(); i++) {
		cout <<setfill('0') <<setw(3) <<i <<": ";
		cout <<setfill(' ');
		cout <<setw(5) <<vf1[i] <<" ";
		cout <<setw(5) <<vf[i] <<" ";
		cout <<endl;
	}

	return 0;
} ///:~
