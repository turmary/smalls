//: T04:Stash.cpp {O}
//修改Stash
//使用vector<char>做为它的底层数据结构

#include "Stash.h"
#include <iostream>
#include <cassert>
using namespace std;

void Stash::initialize(int sz) {
	size = sz;
	next = 0;
}

int Stash::add(const void* element) {
	// Copy element into storage,
	// starting at next empty space:
	char* e = (char*)element;
	for(int i = 0; i < size; i++)
		storage.push_back(e[i]);
	next++;
	return(next - 1); // Index number
}

void* Stash::fetch(int index) {
	// Check index boundaries:
	assert(0 <= index);
	if(index >= next)
		return 0; // To indicate the end
	// Produce pointer to desired element:
	return &(storage[index * size]);
}

int Stash::count() {
	return next; // Number of elements in CStash
}

void Stash::cleanup() {
} ///:~
