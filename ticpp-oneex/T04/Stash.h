//: T04:Stash.h
//修改Stash
//使用vector<char>做为它的底层数据结构

#include <vector>

struct Stash {
	int size;      // Size of each space
	int next;      // Next empty space
	// Dynamically allocated array of bytes:
	std::vector<char> storage;
	// Functions!
	void initialize(int size);
	void cleanup();
	int add(const void* element);
	void* fetch(int index);
	int count();
}; ///:~
