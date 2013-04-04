//: C16:SelfCounter.h
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#ifndef SELFCOUNTER_H
#define SELFCOUNTER_H
#include <iostream>

class SelfCounter {
	static int counter;
	int id;

public:
	SelfCounter() : id(counter++) {
		std::cout <<"Created: " <<id <<" &=" <<this <<std::endl;
	}

	SelfCounter(const SelfCounter& rv) : id(rv.id){
		std::cout <<"Copied: " <<id <<" &=" <<this <<" from &=" <<&rv <<std::endl;
	}

	SelfCounter& operator=(const SelfCounter& rv) {
		std::cout
		<<"Assigned " <<rv.id <<" &=" <<&rv
		<<" to " <<id <<" &=" <<this <<std::endl;
		return *this;
	}

	~SelfCounter() {
		std::cout <<"Destroyed: "<<id <<" &=" <<this <<std::endl;
	}

	friend std::ostream& operator<< (std::ostream& os, const SelfCounter& sc){
		return os <<"SelfCounter: " <<sc.id;
	}
};
#endif // SELFCOUNTER_H
///:~
