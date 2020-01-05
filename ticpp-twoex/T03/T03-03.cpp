//: T03:T03-03.cpp
// check a string whether is palindrome
// with case insensitive.
#include <string>
#include <iostream>
#include "T03Util.h"
#include "../require.h"
using namespace std;

int main(int argc, const char* argv[]) {
  requireArgs(argc, 1, "Usage: T03-03 <string>");

  istring s(argv[1]);
  if (s == str_rev(s)) {
    cout <<"It is palindrome: *" <<s <<'*' <<endl;
  } else {
    cout <<"Not a palindrome: *" <<s <<'*' <<endl;
  }
  return 0;
}
///:~
