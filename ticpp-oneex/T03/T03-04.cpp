//: T03:T03-04.cpp
// 修改Menu.cpp
// 使用switch代替if

#include <iostream>
using namespace std;

int main() {
	int f_exit = 0;	// add
	char c; // To hold response
	// while(true) {
	while (!f_exit) {
		cout << "MAIN MENU:" << endl;
		cout << "l: left, r: right, q: quit -> ";

		cin >> c;
		// if(c == 'q')
		switch(c) {
		case 'q':
			f_exit = 1;
			break; // Out of "while(1)"
		// if(c == 'l') {
		case 'l':
			cout << "LEFT MENU:" << endl;
			cout << "select a or b: ";
			cin >> c;
			// if(c == 'a') {
			switch(c) {
			case 'a':
				cout << "you chose 'a'" << endl;
				continue; // Back to main menu
			// }
			// if(c == 'b') {
				break;	// add
			case 'b':
				cout << "you chose 'b'" << endl;
				continue; // Back to main menu
			//}
			//else {
				break;	// add
			default:
				cout << "you didn't choose a or b!"
				  << endl;
				continue; // Back to main menu
				break;	// add
			}
		// }
		// if(c == 'r') {
		case 'r':
			cout << "RIGHT MENU:" << endl;
			cout << "select c or d: ";
			cin >> c;
			// if(c == 'c') {
			switch(c) {
			case 'c':
				cout << "you chose 'c'" << endl;
				continue; // Back to main menu
				break;	// add
			// }
			//if(c == 'd') {
			case 'd':
				cout << "you chose 'd'" << endl;
				continue; // Back to main menu
				break;	// add
			// }
			// else {
			default:
				cout << "you didn't choose c or d!" 
				  << endl;
				continue; // Back to main menu
				break;	// add
			}
		}
		cout << "you must type l or r or q!" << endl;
	}
	cout << "quitting menu..." << endl;
} ///:~
