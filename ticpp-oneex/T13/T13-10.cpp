//: T13:T13-10.cpp
// retrival new's memory available for you platfrom

#include <iostream>
#include <cstdlib>
#include <new>
using namespace std;

int count_local = 0;

void out_of_memory() {
	cerr <<"memory exhausted after " <<count_local * 1000 * sizeof(int)
	     <<" bytes allocations!" <<endl;
	exit(1);
}

int main() {
	set_new_handler(out_of_memory);
	while(1) {
		count_local++;
		new int[1000]; // Exhausts memory
	}
} ///:~
