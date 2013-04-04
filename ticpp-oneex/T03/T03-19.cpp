//: T03:T03-19.cpp
//修改ArrayAddresses.cpp
//使之能处理char, long, int, float及double类型

#include <iostream>
using namespace std;

#define TYPE_ADDRESS(TYPE)				\
	TYPE a_##TYPE[10];				\
							\
	cout <<"sizeof(" 				\
	#TYPE						\
	") = " <<sizeof(TYPE) <<endl;			\
	for (int i = 0; i < 10; i++) {			\
		cout <<"&a_" #TYPE "[" <<i <<"] = "	\
		     <<(long)&a_##TYPE [i] <<endl;	\
	}

int main() {
	TYPE_ADDRESS(char);
	TYPE_ADDRESS(int);
	TYPE_ADDRESS(long);
	TYPE_ADDRESS(float);
	TYPE_ADDRESS(double);
} ///:~
