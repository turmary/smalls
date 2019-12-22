//: T02:T02-01.h
// Test vector members: push_back(),
//   front(), back(), pop_back(),
//   at(), size()
#ifndef T02_01_H
#define T02_01_H
#include <vector>
#include <stdexcept>
#include "../TestSuite/Test.h"

class VectorTest : public TestSuite::Test {
  std::vector<int> v;
public:
  VectorTest() {}
  void run() {
    testFunctions();
    testExceptions();
  }
  void testFunctions() {
    test_(v.size() == 0);

    v.push_back(5);
    test_(v.size() == 1);
    test_(v.front() == 5);
    test_(v.back() == 5);

    v.push_back(3);
    test_(v.size() == 2);
    test_(v.front() == 5);
    test_(v.back() == 3);

    test_(v.at(1)  == 3);
    test_(v.at(0)  == 5);

    v.pop_back();
    test_(v.size() == 1);
    test_(v.front() == 5);
    test_(v.back() == 5);
  }
  void testExceptions() { 
    try {
      v.at(v.size());
      fail_("No exception when access v.at(v.size())");
    } catch(std::out_of_range& e) {
      succeed_();
    }
  }
};
#endif// T02_01_H
///:~
