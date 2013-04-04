//: T03:T03-18.cpp
//连续定义两个数组,索引它们,
//越界访问第一个数组到第二个

#include <iostream>
using namespace std;

void print(const char* name, int* array, int size) {
	for (int i = 0; i < size; i++) {
		cout <<name <<"[" <<i <<"] ("
		     <<hex <<(long)(&array[i]) <<") = "
		     <<dec <<array[i] <<endl;
	}
}

#define PRT(A, B, C, D)				\
	print(#A, A, sizeof A / sizeof *A);	\
	print(#B, B, sizeof B / sizeof *B);	\
	cout <<#C " (" <<hex <<(long)(&C) <<") = "	\
	     <<dec <<C <<endl;			\
	print(#D, D, sizeof D / sizeof *D);

int main() {
	int d[] = {9, 10, 11, 12,};
	char c = 'x';
	int b[] = {5, 6, 7, 8,};
	int a[] = {1, 2, 3, 4,};

	PRT(a, b, c, d);
	cout <<"\nIndex off the end of a:\n";
	a[4] = 47;

	PRT(a, b, c, d);
	cout <<"\nIndex off the end of b:\n";
	b[4] = 47;

	PRT(a, b, c, d);
	cout <<"\nAbuse c with pointers and casts:\n";
	*((double*)&c) = 99.99;
	
	PRT(a, b, c, d);

	return 0;
} ///:~
