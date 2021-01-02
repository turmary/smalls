//: T05:T05-05.cpp
// Write a function template that takes a single type parameter (T)
// and accepts four function arguments:
//   an array of T,
//   a start index,
//   a stop index (inclusive),
//   and an optional initial value.
// The function returns the sum of all the array elements
// in the specified range and the initial value.
// Use the default constructor of T for the default initial value.
#include <iostream>
#include "../require.h"
using namespace std;

template<typename T> T function(T array[], int start, int end, T initial = T()) {
	T s = initial;
	for (int i = start; i < end; i++) {
		s += array[i];
	}
	return s;
}

template double function<double>(double [], int, int, double = double(0.0));
template    int function<int>   (int    [], int, int, int = 0);

int main(int argc, char* argv[]) {
	uint8_t u8array[] = { 1, 3, 5, 7, 9};
	cout <<"sum u8array = "
	     <<(int)function(u8array, 0, sizeof u8array)
	     <<endl;

	int intarray[] = { 1, 2, 3, 4, 5, 6, 7};
	cout <<"sum intarray = "
	     <<function(intarray, 0, sizeof intarray / sizeof intarray[0])
	     <<endl;

	double dblarray[] = { 0.1, 3.0, 5.0, 0.7, 0.9};
	cout <<"sum dblarray = "
	     <<function(dblarray, 0, sizeof dblarray / sizeof dblarray[0])
	     <<endl;
	return 0;
}
///:~
