//: T07:T07-01.cpp
//创建一个包含string对象的Text类
//用于保存文件内容

#include "../require.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Text {
	string s;
public:
	Text(void): s("") {};
	Text(string fileName);
	string contents(void);
};

Text::Text(string fileName): s("") {
	ifstream in(fileName.c_str());
	assure(in, fileName.c_str());

	stringstream ss;
	ss << in.rdbuf();
	s = ss.str();
}

string Text::contents(void) {
	return s;
}

int main(void) {
	Text t("T07-01.cpp");

	cout <<t.contents() <<endl;

	return 0;
} ///:~
