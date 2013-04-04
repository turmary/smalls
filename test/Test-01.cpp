#include <iostream>
using namespace std;

int main() {
	int i;

	while (!(cin >> i)) {
		cin.clear();
		cin.ignore();
	}

	cout <<"inputed "<<i <<endl;

	return 0;
}
