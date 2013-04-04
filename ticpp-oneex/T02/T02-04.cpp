//: T02:T02-04.cpp
// 统计文件中特定单词的出现次数

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

const string fname = "t02-04.cpp";

int main(int, char* []) {
	vector<string> words;
	ifstream in(fname.c_str());

	string word;
	while (in >> word) {
		words.push_back(word);
	}

	string tword;
	cout <<"word?";
	cin >> tword;

	cout <<"word \"" <<tword;
	cout <<"\" count in file " <<fname <<endl;

	int cnt = 0;
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == tword) {
			cnt++;
		}
	}

	cout <<cnt <<endl;

	return 0;
} ///:~
