//: T05:T05-03.cpp
// Write a class template that uses a vector
// to implement a stack data structure.
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "VarStack.h"
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]) {
	// Stack<int, vector> sc;
	// Stack<int, list> sc;
	Stack<int, deque> sc;

	for (int i = 0; i < 25; i++)
		sc.push(int(i * 3));

	// OK to peek(), result is a temporary
	cout <<"***** ******" <<endl;
	cout <<sc.peek() <<endl;
	cout <<"***** ******" <<endl;

	for (int k = 0; k < 25; k++)
		cout <<sc.pop() <<endl;
}
///:~
