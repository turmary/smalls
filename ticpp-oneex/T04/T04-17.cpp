//: T04:T04-17.cpp
//ʹ��new��̬�����������͵Ĵ洢��

#include <iostream>
using namespace std;

int main() {
	int* pi = new int;
	long* pl = new long;
	char* pc = new char[100];
	float* pf = new float[10];

	cout <<"&int = " <<pi <<endl;
	cout <<"&long = " <<pl <<endl;
	cout <<"&char = " <<(void*)pc <<endl;
	cout <<"&float = " <<pf <<endl;

	delete pi;
	delete pl;
	delete []pc;
	delete []pf;
} ///:~
