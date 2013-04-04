//: T04:T04-10.c
//写一个函数及有成员函数的类
//分别用C和C++编译器生成汇编
//观察生成的函数名

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
