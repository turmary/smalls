//: T02:T02-03.cpp
// ͳ���ļ��Կո�����ĵ�����Ŀ

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

const string fname = "t02-03.cpp";

int main(int, char* []) {
	vector<string> words;
	ifstream in(fname.c_str());

	string word;
	while (in >> word) {
		words.push_back(word);
	}

	cout <<"words count in file " <<fname <<endl;
	cout << words.size() <<endl;

	cout <<"they are:" <<endl;
	for (int i = 0; i < words.size(); i++) {
		cout <<setfill('0') <<setw(3) <<i <<": ";
		cout <<words[i] <<endl;
	}

	return 0;
} ///:~
