//: T10:T10-25.h
//创建一个包含<string>和<iostream>的头文件

#ifndef __T10_25_H__
#define __T10_25_H__

#include <string>
#include <iostream>

class fourth {
	std::string s;
public:
	fourth(std::string s): s(s) {
		return;
	}

	int print(void) {
		std::cout <<s <<std::endl;
		return 0;
	}
};

class fifth {
	static double sd;
	static long sl;
public:
	static int print(void) {
		std::cout <<"sd = " <<sd <<std::endl;
		std::cout <<"sl = " <<sl <<std::endl;

		return 0;
	}
};

class sixth {
	int inner;
public:
	sixth(int i): inner(i) {}
	int print(void) {
		std::cout <<"inner = " <<inner <<std::endl;
		return 0;
	}
};

#endif //__T10_25_H__

///:~
