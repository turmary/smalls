//: T02:T02-09.cpp
// 创建三个vector<float>
// 第三个中的元素
// 是前两个中对应元素值相加的结果

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

	vector<float> vf2;
	cout <<"vf2?" <<endl;
	for (int i = 0; i < FLOAT_COUNT; i++) {
		cin >>f;
		vf2.push_back(f);
	}

	vector<float> vf;
	for (int i = 0; i < FLOAT_COUNT; i++) {
		f = vf1[i] + vf2[i];
		vf.push_back(f);
	}

	cout <<"The    vf = vf[1] + vf[2]: " <<endl;
	for (int i = 0; i < vf.size(); i++) {
		cout <<setfill('0') <<setw(3) <<i <<": ";
		cout <<setfill(' ');
		cout <<setw(5) <<vf[i] <<"=";
		cout <<setw(5) <<vf1[i] <<"+";
		cout <<setw(5) <<vf2[i] <<" ";
		cout <<endl;
	}

	return 0;
} ///:~
