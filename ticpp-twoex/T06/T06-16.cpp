//: T06: T06-16.cpp
// Test the speed of your computer. Call srand(time(0)), then make an array of random numbers.
// Call srand(time(0)) again and generate the same number of random numbers in a second array.
// Use equal() to see if the arrays are the same. (If your computer is fast enough,
// time(0) will return the same value both times it is called.)
// If the arrays are not the same, sort them and use mismatch() to see where they differ.
// If they are the same, increase the length of your array and try again.
#include <algorithm>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "PrintSequence.h"
#include "Generators.h"
using namespace std;

const int SZ = 20 * 1000 * 1000;
URandGen ug(RAND_MAX);

typedef vector<unsigned> vector_;

int make_random_numbers(vector_& v) {
  srand(time(0));  // Randomize
  v.reserve(SZ);
  generate_n(back_inserter(v), SZ, (unsigned (*)())&rand/*ug*/);
  return 0;
}

int main(int argc, char* argv[]) {
  vector_ va;
  make_random_numbers(va);
  print(va.begin(), va.begin() + 10, "va");

  vector_ vb;
  make_random_numbers(vb);
  print(vb.begin(), vb.begin() + 10, "vb");

  if (equal(va.begin(), va.end(), vb.begin())) {
    cout << "equal.";
    return 0;
  }

  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  pair<vector_::iterator, vector_::iterator> p = mismatch(va.begin(), va.end(), vb.begin());
  cout <<"Differ position: " << p.first - va.begin() <<endl;
  cout <<"               : " << *p.first <<", " << *p.second <<endl;

  return 1;
} ///:~
