//: C10:StaticDestructors.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Static object destructors
#include <fstream>
using namespace std;

extern ofstream out;
ofstream out("statdest.out"); // Trace file

class Obj {
  char c; // Identifier
public:
  Obj(char cc) : c(cc) {
    out << "Obj::Obj() for " << c << endl;
  }
  ~Obj() {
    out << "Obj::~Obj() for " << c << endl;
  }
};

Obj a('a'); // Global (static storage)
// Constructor & destructor always called

//definition here will be error
//ofstream out("statdest.out"); // Trace file

void f() {
  static Obj b('b');
}

void g() {
  static Obj c('c');
}

int global_int = 255;

int main() {
  out << "inside main()" << endl;
  // g();	// not called
  f(); // Calls static constructor for b
  out << "leaving main()" << endl;
} ///:~
