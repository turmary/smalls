//: T04:T04-10.c
//дһ���������г�Ա��������
//�ֱ���C��C++���������ɻ��
//�۲����ɵĺ�����

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

int main() {
	_A_(0);		// __A_
	_B_(0.0);	// __B_
	_C_('0');	// __C_
	_D_(1, "hello");// __D_

	return 0;
}
///:~
