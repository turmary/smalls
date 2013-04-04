//: T03:T03-20.cpp
//�޸�ArrayAddresses.cpp
//ʹ֮�ܴ���StructArray.cpp�е�����

#include <iostream>
using namespace std;

typedef struct {
  int i, j, k;
} ThreeDpoint;

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
	TYPE_ADDRESS(ThreeDpoint);
} ///:~
