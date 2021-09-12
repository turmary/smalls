//: T06:T06-08.cpp
// Modify FunctionObjects.cpp so that it templatizes the main body of
// tests so you can choose which type you’re going to test.
// (You’ll have to pull most of main() out into a
// separate template function.)
//{L} Generators
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include "Generators.h"
#include "PrintSequence.h"
using namespace std;

template<typename Contain, typename UnaryFunc>
void testUnary(Contain& source, Contain& dest,
  UnaryFunc f) {
  transform(source.begin(), source.end(), dest.begin(), f);
}

template<typename Contain1, typename Contain2,
  typename BinaryFunc>
void testBinary(Contain1& src1, Contain1& src2,
  Contain2& dest, BinaryFunc f) {
  transform(src1.begin(), src1.end(),
    src2.begin(), dest.begin(), f);
}

// Executes the expression, then stringizes the
// expression into the print statement:
#define T(EXPR) EXPR; print(r.begin(), r.end(), \
  "After " #EXPR);
// For Boolean tests:
#define B(EXPR) EXPR; print(br.begin(), br.end(), \
  "After " #EXPR);

// Boolean random generator:
struct BRand {
  bool operator()() { return rand() % 2 == 0; }
};

template <class T>
int theAlgoSeq(const int SZ, const int MAX) {
  vector<T> x(SZ), y(SZ), r(SZ);
  // An integer random number generator:
  TRandGen<T> urg(MAX);
  generate_n(x.begin(), SZ, urg);
  generate_n(y.begin(), SZ, urg);
  // Add one to each to guarantee nonzero divide:
  transform(y.begin(), y.end(), y.begin(),
    bind2nd(plus<T>(), 1));
  // Guarantee one pair of elements is ==:
  x[0] = y[0];
  print(x.begin(), x.end(), "x");
  print(y.begin(), y.end(), "y");
  // Operate on each element pair of x & y,
  // putting the result into r:
  T(testBinary(x, y, r, plus<T>()                ));
  T(testBinary(x, y, r, minus<T>()               ));
  T(testBinary(x, y, r, multiplies<T>()          ));
  T(testBinary(x, y, r, divides<T>()             ));
  // T(testBinary(x, y, r, modulus<T>()));
  T(testUnary(x, r, negate<T>()                  ));
  vector<bool> br(SZ); // For Boolean results
  B(testBinary(x, y, br, equal_to<T>()           ));
  B(testBinary(x, y, br, not_equal_to<T>()       ));
  B(testBinary(x, y, br, greater<T>()            ));
  B(testBinary(x, y, br, less<T>()               ));
  B(testBinary(x, y, br, greater_equal<T>()      ));
  B(testBinary(x, y, br, less_equal<T>()         ));
  B(testBinary(x, y, br, not2(greater_equal<T>())));
  B(testBinary(x, y, br, not2(less_equal<T>())   ));
  /*
  vector<bool> b1(SZ), b2(SZ);
  generate_n(b1.begin(), SZ, BRand());
  generate_n(b2.begin(), SZ, BRand());
  print(b1.begin(), b1.end(), "b1");
  print(b2.begin(), b2.end(), "b2");
  B(testBinary(b1, b2, br, logical_and<T>()));
  B(testBinary(b1, b2, br, logical_or<T>()));
  B(testUnary(b1, br, logical_not<T>()));
  B(testUnary(b1, br, not1(logical_not<T>())));
  */
  return 0;
}

int main(int argc, char* argv[]) {
  const int SZ = 5;
  const int MAX = 50;

  srand(time(0));  // Randomize
  theAlgoSeq<int>(SZ, MAX);
  theAlgoSeq<double>(SZ, MAX);
  theAlgoSeq<uint8_t>(SZ, MAX);
} ///:~
