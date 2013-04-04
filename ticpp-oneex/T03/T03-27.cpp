//: T03:T03-27.cpp
//定义const和volatile double数组
//转换成non-const和non-volatile并输出

#include <iostream>
using namespace std;

volatile double volatile_arr[] = {1.1, 2.2, 3.3, 4.4, 5.5,};
// const double const_arr[] = {1.1, 2.2, 3.3, 4.4, 5.5,};

int main() {
	const double const_arr[] = {1.1, 2.2, 3.3, 4.4, 5.5,};
	double* p;

	cout <<"&const_arr = " <<&const_arr[0] <<endl;
	cout <<"&volatile_arr = " <<const_cast<double*>(&volatile_arr[0]) <<endl;

	cout.flush();

	p = const_cast<double*>(volatile_arr);
	for (int i = 0; i < sizeof volatile_arr / sizeof volatile_arr[0]; i++) {
		p[i] += 0.1;
	}

	p = const_cast<double*>(const_arr);
	for (int i = 0; i < sizeof const_arr / sizeof const_arr[0]; i++) {
		p[i] += 0.1;
	}

	for (int i = 0; i < sizeof volatile_arr / sizeof volatile_arr[0]; i++) {
		cout <<"volatile_arr[" <<i <<"] = " <<volatile_arr[i] <<endl;
	}

	for (int i = 0; i < sizeof const_arr / sizeof const_arr[0]; i++) {
		cout <<"const_arr[" <<i <<"] = " <<const_arr[i] <<endl;
	}

	return 0;
} ///:~
