//: T02:T02-07.cpp
// 一次显示文件一行
// 按回车显示下一行

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
	vector<string> v;
	ifstream in(argv[1]);

	string line;
	while (getline(in, line)) {
		v.push_back(line);
	}

	for (int i = 0; i < v.size(); i++) {
		cout <<v[i];
		cin.get();
	}

	return 0;
} ///:~
