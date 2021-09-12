//: T06: T06-13.cpp
// Modify CalcInventory.cpp so that it will find all the objects
// that have a quantity that’s less than a certain amount.
// Provide this amount as a command-line argument,
// and use copy_if( ) and bind2nd( ) to
// create the collection of values less than the target value.
#include <algorithm>
#include <ctime>
#include <vector>
#include <cstdlib>
#include "../require.h"
#include "Inventory.h"
#include "PrintSequence.h"
using namespace std;

// To calculate inventory totals:
class InvAccum {
  int quantity;
  int value;
public:
  InvAccum() : quantity(0), value(0) {}
  void operator()(const Inventory& inv) {
    quantity += inv.getQuantity();
    value += inv.getQuantity() * inv.getValue();
  }
  friend ostream&
  operator<<(ostream& os, const InvAccum& ia) {
    return os << "total quantity: " << ia.quantity
              << ", total value: " << ia.value;
  }
};

int main(int argc, char* argv[]) {
  requireArgs(argc, 1, "T06-13 <total-value>");
  int total = atoi(argv[1]);

  vector<Inventory> vi;
  srand(time(0));  // Randomize
  generate_n(back_inserter(vi), 15, InvenGen());
  print(vi.begin(), vi.end(), "vi");
  InvAccum ia = for_each(vi.begin(),vi.end(), InvAccum());
  cout << ia << endl;

  vector<Inventory> vl;
  Inventory iy('z', 1, total);
  copy_if(vi.begin(), vi.end(), back_inserter(vl), bind2nd(less<Inventory>(), iy));
  cout << endl;
  print(vl.begin(), vl.end(), "vl (< z)");
} ///:~
