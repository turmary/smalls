//: C13:Counted.h
// 创建一个class Counted
// 它有static的count成员对该类型的对象计数
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
