//: C06:Generators.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Different ways to fill sequences.
#ifndef GENERATORS_H
#define GENERATORS_H
#include <cstring>
#include <set>
#include <cstdlib>

// A generator that can skip over numbers:
class SkipGen {
  int i;
  int skp;
public:
  SkipGen(int start = 0, int skip = 1)
  : i(start), skp(skip) {}
  int operator()() {
    int r = i;
    i += skp;
    return r;
  }
};

// Generate unique random numbers from 0 to mod:
class URandGen {
  std::set<int> used;
  int limit;
public:
  URandGen(int lim) : limit(lim) {}
  int operator()() {
    while(true) {
      int i = int(std::rand()) % limit;
      if(used.find(i) == used.end()) {
        used.insert(i);
        return i;
      }
    }
  }
};

// Generate unique float random numbers from 0 to mod:
class FRandGen {
  std::set<float> used;
  int limit;
public:
  FRandGen(int lim) : limit(lim) {}
  float operator()() {
    while(true) {
      float i = (std::rand() % (limit * 100)) / 100.0;
      if(used.find(i) == used.end()) {
        used.insert(i);
        return i;
      }
    }
  }
};


// Generate unique T-type random numbers from 0 to mod:
template <class T>
class TRandGen {
  std::set<T> used;
  int limit;
public:
  TRandGen(int lim) : limit(lim) {}
  float operator()() {
    while(true) {
      T i = (std::rand() / double(RAND_MAX)) * limit;
      return i;
      /*
      if(used.find(i) == used.end()) {
        used.insert(i);
        return i;
      }
      */
    }
  }
};


// Produces random characters:
class CharGen {
  static const char* source;
  static const int len;
public:
  char operator()() {
    return source[std::rand() % len];
  }
};
#endif // GENERATORS_H ///:~
