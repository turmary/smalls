//: T12:T12-24.cpp
//����һ������string���ݳ�Ա����
//��ʹ�����string��Ա
//���ǲ�Ҫ�����������캯����=������
//�����ڶ�����,������һ�����͵����ݳ�Ա
//չʾ���ǵĿ������캯����=������
//����������ȷ��������

#include <string>
#include <iostream>
using namespace std;

class inner {
	string s;
public:
	inner(const string si = string("")): s(si) {}
	void print(void) {
		cout <<s <<endl;
	}
};

class outter {
	inner in;
public:
	outter(string s): in(s) {}
	void print(void) {
		in.print();
	}
};

int main(void) {
	outter i = string("hello world");
	outter i2 = i;
	i2.print();
	
	outter i3 = string("i3");
	i = i3;
	i.print();
	return 0;
} ///:~
