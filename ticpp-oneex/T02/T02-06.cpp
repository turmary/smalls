//: T02:T02-06.cpp
// �޸�Fillvector.cpp
// ����������Ϊһ���ַ���
// �����,��Ҫ�к�

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int main(int, char* []) {
	vector<string> v;
	ifstream in("T02-06.cpp");

	string line;
	while (getline(in, line)) {
		v.push_back(line);
	}

	string entire;

	for (int i = 0; i < v.size(); i++) {
		entire += v[i];
	}

	cout <<entire <<endl;

	return 0;
} ///:~
