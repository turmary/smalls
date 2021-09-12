//: T06:T06-04.cpp
// Write an anagram generator that takes a word as
// a command-line argument and produces all possible
// permutations of the letters.
#include <iostream>
#include <algorithm>
#include <cctype>
#include <unistd.h>
#include "../require.h"
using namespace std;

/*
current: 2431
index  : 0123
next   : 3124

__i = 4
--__i // __i = 3
for (;;)
  {
    __ii = __i; // __ii = 3
    --__i;      // __i  = 2
    if (*__i < *__ii) // 3 < 1 false
  }

  {
    __ii = __i; // __ii = 2
    --__i;      // __i  = 1
    if (*__i < *__ii) // 4 < 3 false
  }

  {
    __ii = __i; // __ii = 1
    --__i;      // __i  = 0
    if (*__i < *__ii) { // 2 < 4 true
      __j = 4;
      while (!(*__i < *--__j)); //  ! 2 < 1 = true
      while (!(*__i < *--__j)); //  ! 2 < 3 = false
      __i = 0; __j = 2;         //  2 < 3
      iter_swap(__i, __j);      //  list = 3421
      reverse(__ii, __last);    //  list = 3124
    }
  }
*/

int main(int argc, const char* argv[]) {
	requireArgs(argc, 1, "usage: T06-04 <a-string-to-permutation>");

	string s(argv[1]);

	int i, nf = 1;
	for (i = 2; i <= s.size(); i++) {
		nf *= i;
	}

	for (i = 0; i < nf; i++) {
		cout <<s <<endl;
		if (! next_permutation(s.begin(), s.end())) {
			break;
		}
	}

	return 0;
}
///:~

