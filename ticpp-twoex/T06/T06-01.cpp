//: T06:T06-01.cpp
// Create a generator that returns the current value of clock( ) (in <ctime>).
// Create a list<clock_t>, and filla it with your generator using generate_n( ).
// Remove any duplicates in the list and print it to cout using copy( ).
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <ctime>
#include "../require.h"
using namespace std;

class ClockGenerator {
public:
	clock_t operator() () {
		return clock() / 10;
	}
};

class ClockRemoveDup {
	clock_t lastClock;
public:
	bool operator() (clock_t clk) {
		bool r = (clk == lastClock);
		lastClock = clk;
		return r;
	}
};

int main(int argc, const char* argv[]) {
	const int SZ = 20;
	list<clock_t> ll;
	ClockGenerator cg;

	/*
	 * generate_n() will FAIL if ll without initial size
	 * and generate_n without back_inserter
	 */
	generate_n(back_inserter(ll), SZ, cg);

	// ll.push_front(*ll.begin());
	cout <<"CLOCKS_PER_SEC = " <<CLOCKS_PER_SEC <<endl;
	cout <<"LIST SIZE      = " <<ll.size() <<endl;

	#if 1
	// ClockRemoveDup crd;
	remove_copy_if(
	               ll.begin(), ll.end(), ostream_iterator<clock_t>(cerr, "\n"),
		       ClockRemoveDup());
	//             crd);
	#else
	copy(ll.begin(), ll.end(), ostream_iterator<clock_t>(cerr, "\n"));
	#endif

	/*
	typedef list<clock_t>::iterator lli;
	for (lli f = ll.begin(); f != ll.end(); f++) {
		cerr <<*f <<endl;
	}
	*/
	return 0;
}
///:~
