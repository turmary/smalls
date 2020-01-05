//: T03:T03Util.h
#ifndef T03UTIL_H
#define T03UTIL_H
#include <vector>
#include <string>
#include <cstring>
#include "ichar_traits.h"
using std::toupper;
using std::tolower;

std::string str_rev(const std::string& s);
std::istring str_rev(const std::istring& s);
bool is_palindrome(const std::string& s);
std::vector<std::string> to_words(const std::string& s);

// Make an uppercase copy of s
inline std::string upperCase(const std::string& s) {
  std::string upper(s);
  for(size_t i = 0; i < s.length(); ++i)
    upper[i] = toupper(upper[i]);
  return upper;
}

// Make a lowercase copy of s
inline std::string lowerCase(const std::string& s) {
  std::string lower(s);
  for(size_t i = 0; i < s.length(); ++i)
    lower[i] = tolower(lower[i]);
  return lower;
}

std::string& replaceAll(std::string& context,
  const std::string& from, const std::string& to);

// case insensitive
std::string& ireplaceAll(std::string& context,
  const std::string& from, const std::string& to);

#endif // T03UTIL_H ///:~
