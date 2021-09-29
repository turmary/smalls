//: T06: T06-15.cpp
// Fill a vector<double> with numbers representing angles in radians.
// Using function object composition, take the sine of all the elements
// in your vector (see <cmath>).
#include <algorithm>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "PrintSequence.h"
#include "Generators.h"
using namespace std;

double to_sine(double angle) {
  return std::sin(angle);
}

int main(int argc, char* argv[]) {
  const int SZ = 10;
  TRandGen<double> tg(M_PI * 2);

  srand(time(0));  // Randomize

  vector<double> vd;
  generate_n(back_inserter(vd), SZ, tg);
  print(vd.begin(), vd.end(), "vd");

  vector<double> vt;
  transform(vd.begin(), vd.end(), back_inserter(vt), ptr_fun(to_sine));
  print(vt.begin(), vt.end(), "vt");
} ///:~
