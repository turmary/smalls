//: T03:T03-04.cpp
// check a string whether is palindrome
// with case insensitive and ignore space/punctuation.
#include <string>
#include <cstring>
#include <iostream>
#include "T03Util.h"
#include "../require.h"
using namespace std;

int main(int argc, const char* argv[]) {
  requireArgs(argc, 1, "Usage: T03-04 <string>");

  string s(argv[1]);
  if (is_palindrome(s)) {
    cout <<"It is palindrome: *" <<s <<'*' <<endl;
  } else {
    cout <<"Not a palindrome: *" <<s <<'*' <<endl;
  }
  return 0;
}
///:~
