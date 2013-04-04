//: T10:T10-25.cpp
//创建一个包含<string>和<iostream>的头文件

#include "T10-25.h"

double fifth::sd = 25.2;
long fifth::sl = 25;

class sixth_inc {
	static const int sci[];
	static int si[];
	static sixth s;
public:
	static int display(void);
};

sixth sixth_inc::s(2);
const int sixth_inc::sci[] = {1, 2, 3, 4, 5,};
int sixth_inc::si[] = {6, 7, 8, 9};

int sixth_inc::display(void) {
	for(int i = 0; i < sizeof sci / sizeof sci[0]; i++) {
		std::cout <<"sci[" <<i <<"] = " <<sci[i] <<std::endl;
	}
	for(int i = 0; i < sizeof si / sizeof si[0]; i++) {
		std::cout <<"si[" <<i <<"] = " <<si[i] <<std::endl;
	}
	return s.print();
}

class fourth_inc {
	static const fourth scf[];
	static fourth sf[];
public:
	static int display(void);
};

const fourth fourth_inc::scf[] = {
	fourth("hello"), 
	fourth("world"), 
	fourth("!"),
};
fourth fourth_inc::sf[] = {
	fourth("this"),
	fourth("is"),
	fourth("tary"),
	fourth("speaking"),
	fourth("!"),
};

int fourth_inc::display(void) {
	for(int i = 0; i < sizeof scf / sizeof scf[0]; i++) {
		((fourth*)&scf[i])->print();
	}
	for(int i = 0; i < sizeof sf / sizeof sf[0]; i++) {
		sf[i].print();
	}
	return 0;
}

int s_eight_function (void) {
	struct s_eight {
		int inner;
	public:
		s_eight(void): inner(0) {}
		int print(void) {
			std::cout <<"inner = " <<inner <<std::endl;
			return 0;
		}
	};

	s_eight sea[5];
	for (int i = 0; i < 5; i++) {
		sea[i].print();
	}

	return 0;
}


int main() {
	fourth f("hello world!");

	f.print();

	fifth::print();
	
	sixth_inc::display();

	fourth_inc::display();

	s_eight_function();
	
	return 0;
}
///:~
