//: T03:T03-08.cpp
// 打印所有三图形字符(trigraph)

#include <string>
#include <iostream>
using namespace std;

int main() {
	string asciis[] = {
		"#",
		"[",
		"\\",
		"]",
		"^",
		"{",
		"|",
		"}",
		"~",
	};
	string trigraphs[] = {
		"??=",
		"??(",
		"??/??/",
		"??)",
		"??'",
		"??<",
		"??!",
		"??>",
		"??-",
	};

	cout <<"trigraphs  asciis" <<endl;

	for (int i = 0; i < sizeof asciis / sizeof asciis[0]; i++) {
		cout <<trigraphs[i] <<"\t" <<asciis[i] <<endl;
	}
} ///:~
