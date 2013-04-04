//: T16:AutoCheck.h
#ifndef __AUTOCHECK_H__
#define __AUTOCHECK_H__
#include "../require.h"
#include <iostream>
// Standard C++ Library container
#include <set>
#include <string>

class AutoCheck {
	static int count;
	int id;

	class CleanupCheck {
		std::set<AutoCheck*> trace;
	public:
		void add(AutoCheck* ap) {
			trace.insert(ap);
		}
		void remove(AutoCheck* ap) {
			require(trace.erase(ap) == 1,
			  "Attempt to delete AutoCheck twice");
		}
		~CleanupCheck() {
			std::cout <<"~CleanupCheck()" <<std::endl;
			require(trace.size() == 0,
			  "Not all AutoCheck objects cleaned up");
		}
	};

	static CleanupCheck verifier;

	// Prevent assignment and copy-construction:
	void operator= (const AutoCheck&);

public:
	AutoCheck(): id(count++) {
		verifier.add(this);	// Register itself
		std::cout <<"created[" <<id <<"]" <<std::endl;
	}

	AutoCheck(const AutoCheck& r): id(count++) {
		verifier.add(this);
		std::cout <<"copyed[" <<id <<"] from [" <<r.id <<"]" <<std::endl;
	}

	~AutoCheck() {
		std::cout <<"destroying[" <<id <<"]" <<std::endl;
		verifier.remove(this);
	}

	// Print both objects and pointers:
	friend std::ostream& operator<< (std::ostream& os, const AutoCheck& ac) {
		return os <<"AutoCheck " <<ac.id;
	}

	friend std::ostream& operator<<(std::ostream& os, const AutoCheck* ac) {
		return os <<"AutoCheck " <<ac->id;
}};
#endif//__AUTOCHECK_H__
///:~
