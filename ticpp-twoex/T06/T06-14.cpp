//: T06: T06-14.cpp
#include <algorithm>
#include <ctime>
#include <vector>
#include <cstdlib>
#include "PrintSequence.h"
#include "Generators.h"
using namespace std;

int main(int argc, char* argv[]) {
  vector<unsigned> vu;
  srand(time(0));  // Randomize

  // Use UrandGen( ) to generate 100 numbers.
  // (The size of the numbers does not matter.)
  generate_n(back_inserter(vu), 100, URandGen(32768));
  print(vu.begin(), vu.end(), "vu");

  // Find which numbers in your range are congruent mod 23
  // (meaning they have the same remainder when divided by 23).
  
  // Manually pick a random number yourself,
  // and determine whether that number is in your range
  // by dividing each number in the list
  // by your number and checking if the result is 1
  // instead of just using find( ) with your value.

} ///:~
