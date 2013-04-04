//: T03:T03-14.cpp
//修改Ifthen.cpp程序,使用三重if-else运算符

#include <iostream>
using namespace std;

int main() {
	int i;
	cout << "type a number and 'Enter'" << endl;

	cin >> i;
	// if(i > 5)
	// 	cout << "It's greater than 5" << endl;
	// else
	// 	if(i < 5)
	// 		cout << "It's less than 5 " << endl;
	// 	else
	// 		cout << "It's equal to 5 " << endl;
	cout << ((i > 5)
			? "It's greater than 5"
			:((i < 5)
				? "It's less than 5 "
				:"It's equal to 5 "));
	cout <<endl;

	cout << "type a number and 'Enter'" << endl;
	cin >> i;
	// if(i < 10)
	// 	if(i > 5)	// "if" is just another statement
	// 		cout << "5 < i < 10" << endl;
	// 	else
	// 		cout << "i <= 5" << endl;
	// else // Matches "if(i < 10)"
	// 	cout << "i >= 10" << endl;
	cout << ((i < 10)
			?((i > 5)
				? "5 < i < 10"
				:"i <= 5")
			:"i >= 10");
	cout <<endl;
} ///:~
