//: T08:T08-28.cpp
//����һ�����г�Ա����fly()��bird��
//��һ������fly()��rock��

#include <iostream>
using namespace std;

class bird {
	int i;
public:
	bird(int ii = 0): i(ii) {}
	int fly(void) { cout <<"bird.i = " <<i <<endl; }
};

class rock {
	int j;
	int i;
public:
	rock(int ii = 0): i(ii), j(314) {}
	int nothing(void) {}
};

int main() {
	rock r(5);

	void* vp = &r;
	bird* pb = (bird*)vp;
	pb->fly();

	return 0;
} ///:~
