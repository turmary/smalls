//: T03:T03-01.cpp
// reverse a string
#include <string>
#include <iostream>
#include "T03Util.h"
using namespace std;

int main() {
  string s("to_be_reverse");
  s = str_rev(s);
  cout <<"Final string: *" <<s <<'*' <<endl;
  return 0;
}
///:~
