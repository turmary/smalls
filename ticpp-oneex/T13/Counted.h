//: C13:Counted.h
// ����һ��class Counted
// ����static��count��Ա�Ը����͵Ķ������
#ifndef __COUNTED_H__
#define __COUNTED_H__

#include <iostream>

class Counted {
	int id;
	static int count;
public:
	Counted(): id(count++) {
		std::cout <<"id=" <<id
		  <<" it's being created"
		  <<std::endl;
	}
	
	int f(void);

	~Counted() {
		std::cout <<"id=" <<id
		  <<" it's being destroyed"
		  <<std::endl;
	}
};

#endif //__COUNTED_H__ ///:~
