//: T04:T04-10.cpp
//дһ���������г�Ա��������
//�ֱ���C��C++���������ɻ��
//�۲����ɵĺ�����

#include <iostream>
#include <string>
using namespace std;

int _A_(int hello) {
	return 0;
}

float _B_(float hello) {
	return 0.0;
}

char _C_(char hello) {
	return '0';
}

int _D_(int hello, char* s) {
	return hello;
}

struct OnlyOne {
	string onlyMember(void);
};

string OnlyOne::onlyMember(void) {
	return string(__FUNCTION__) + "()";
}

int _E_(OnlyOne* op) {
	return 0;
}

int main() {
	OnlyOne onlyOne;

	_A_(0);		// __Z3_A_i
	_B_(0.0);	// __Z3_B_f
	_C_('0');	// __Z3_C_c
	_D_(1, "hello");// __Z3_D_iPc
	_E_(&onlyOne);	// __Z3_E_P7OnlyOne

	cout <<onlyOne.onlyMember() <<endl;
	return 0;
} ///:~
