//: T02:T02-05.cpp {-xo}
// Find the bug in binarySearch() by using TRACE tech in this chapter.
//{L} ../TestSuite/Test
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <fstream>
#include "../TestSuite/Test.h"
using namespace std;

// This function is only one with bugs
int* binarySearch(int* beg, int* end, int what) {
  // int *start = beg; /* new */
  while(end - beg != 1) {
    // cerr <<"find [" <<(beg - start) <<"," 
    //      <<(end - start) <<"]" <<endl; /* new */
    if(*beg == what) {
      // cerr <<endl; /* new */
      return beg;
    }
    int mid = (end - beg) / 2;

    // if(what <= beg[mid]) end = beg + mid;
    if(what < beg[mid]) end = beg + mid; /* new */

    else beg = beg + mid;
  }
  // cerr <<endl; /* new */
  if (what == *beg) return beg; /* new */
  return 0;
}

class BinarySearchTest : public TestSuite::Test {
  enum { SZ = 10 };
  int* data;
  int max; // Track largest number
  int current; // Current non-contained number
               // Used in notContained()
  // Find the next number not contained in the array
  int notContained() {
    while(data[current] + 1 == data[current + 1])
      ++current;
    if(current >= SZ) return max + 1;
    int retValue = data[current++] + 1;
    return retValue;
  }
  void setData() {
    data = new int[SZ];
    assert(!max);
    // Input values with increments of one.  Leave
    // out some values on both odd and even indexes.
    for(int i = 0; i < SZ;
        rand() % 2 == 0 ? max += 1 : max += 2)
      data[i++] = max;
  }
  void testInBound() {
    // Test locations both odd and even
    // not contained and contained
    for(int i = SZ; --i >=0;)
      test_(binarySearch(data, data + SZ, data[i]));
    for(int i = notContained(); i < max;
        i = notContained())
      test_(!binarySearch(data, data + SZ, i));
  }
  void testOutBounds() {
    // Test lower values
    for(int i = data[0]; --i > data[0] - 100;)
      test_(!binarySearch(data, data + SZ, i));
    // Test higher values
    for(int i = data[SZ - 1];
        ++i < data[SZ -1] + 100;)
      test_(!binarySearch(data, data + SZ, i));
  }
public:
  BinarySearchTest() { max = current = 0; }
  void run() {
    setData();
    testInBound();
    testOutBounds();
    delete [] data;
  }
};

int main() {
  srand(time(0));
  BinarySearchTest t;
  t.run();
  return t.report();
} ///:~
