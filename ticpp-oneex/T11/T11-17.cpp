//: T11:T11-17.cpp
//����һ������double*����

#include <iostream>
using namespace std;

class double_ptr {
	double* dptr;

public:
	double_ptr(double d) { dptr = new double(d); }
	// fix problem about function copy by value
	double_ptr(const double_ptr& cd) {
		dptr = new double(*cd.dptr);
	}
#if 0
	double_ptr& operator=(const double_ptr& cd) {
		dptr = new double(*cd.dptr);
	}
#endif
	~double_ptr(void) {
		cout <<*dptr <<endl;
		*dptr = -1;
		delete dptr;
		dptr = NULL;
	}
};

int function(const double_ptr dp) {

	return 0;
}

class simple {
public:
	simple() { };
	simple(const simple&) { };
};

simple first_func(void) {
	return simple();
}

int second_func(const simple& rs) {
	return 0;
}

int third_func(simple s) {
	return 0;
}

class X {
	X() {}
	X(const X&);
public:
	X* clone(void) const{
		return new X;
	}
};

int first_X(const X& rx) {
	X* px = rx.clone();
	delete px;
}

class mmbr_class {
public:
	int arr[5];
	double d;
	int print(void) {
		cout <<"d = " <<d <<endl;
	}
};

int main(int argc, char* argv[]) {
	// �������ֻ��һ������dp
	double_ptr dp = 25;
	// �������ᴴ��һ����ʱ�Ķ���temp(35)
	// ���費����operator=, ���ִ��λ����
	// ��dp.dptr = temp.dptr
	// ��������ʱ*dp.dptr == -1Ϊ��
	// ԭ����*temp.dptr = -1��temp����ʱִ��
	dp = 35;
	function(24);

	second_func(first_func());

	double mmbr_class::*data_p = &mmbr_class::d;
	int (mmbr_class::*func_p)(void) = &mmbr_class::print;

	mmbr_class mmbr;
	mmbr_class* pmmbr = &mmbr;

	mmbr.d = 17.34;
	mmbr.print();

	pmmbr->d = 21.52;
	pmmbr->print();

	mmbr.*data_p = 11.0592;
	(mmbr.*func_p)();

	pmmbr->*data_p = 12.0;
	(pmmbr->*func_p)();

	int (mmbr_class::*arr_p) [5] = &mmbr_class::arr;
	(mmbr.*arr_p)[0] = 15;

	return 0;
} ///:~
