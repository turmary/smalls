//: T16:T16-03.cpp
//{L} AutoCounter
// Modify TPStash.h so that increment value used by
// inflate() can be changed throughout the lifetime of 
// a particular container object.
#include "AutoCounter.h"
#include "TPStash.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
  PStash<AutoCounter> acStash;
  for(int i = 0; i < 10; i++)
    acStash.add(AutoCounter::create());
  cout << "Removing 5 manually:" << endl;
  for(int j = 0; j < 5; j++)
    delete acStash.remove(j);
  cout << "Remove two without deleting them:"
       << endl;
  // ... to generate the cleanup error message.
  //cout << acStash.remove(5) << endl;
  //cout << acStash.remove(6) << endl;
  cout << "The destructor cleans up the rest:"
       << endl;
  // Repeat the test from earlier chapters: 
  ifstream in("TPStash.h");
  assure(in, "TPStash.h");
  PStash<string> stringStash;
  string line;
  while(getline(in, line))
    stringStash.add(new string(line));
  // Print out the strings:
  for(int u = 0; stringStash[u]; u++)
    cout << "stringStash[" << u << "] = "
         << *stringStash[u] << endl;
} ///:~
