//: T16:T16-09.cpp
// {L} SelfCounter
#include "ValueStack.h"
#include "SelfCounter.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	Stack<SelfCounter> sc;

	for (int i = 0; i < 25; i++)
		sc.push(SelfCounter());

	// OK to peek(), result is a temporary
	cout <<"***** ******" <<endl;
	cout <<sc.peek() <<endl;
	cout <<"***** ******" <<endl;

	for (int k = 0; k < 25; k++)
		cout <<sc.pop() <<endl;
}
///:~
