//: T10:T10-10.h
//��֤�����ж����̬������ͷ�ļ������cpp�ļ�����ʱ
//���������ֳ�ͻ

#include <iostream>

class Simple {
	int i;
public:
	Simple(int ii): i(ii) {
		return;
	}

	int set_inner(int ii) {
		i = ii;
		return 0;
	}

	int print(void) {
		std::cout <<"i = " <<i <<std::endl;
		return 0;
	}
};

int output_int(int i);

static int abc = 25;
extern int set_abc_0(int i);
extern int get_abc_0(void);
extern int set_abc_1(int i);
extern int get_abc_1(void);

///:~
