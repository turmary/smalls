//: T04:T04-11.cpp
//��������
//�ֱ�ʹ��Դ��������з�ʽ��������

#include <iostream>
using namespace std;

#define OK_COND

int main() {
#ifdef OK_COND
	cout <<"OK_COND defined!" <<endl;
#else
	cout <<"OK_COND not defined!" <<endl;	
#endif //NDEBUG
	return 0;
} ///:~
