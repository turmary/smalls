//: T05:T05-01.cpp
//����һ����
//����public, private��protected���ݳ�Ա��������Ա

#include <iostream>
using namespace std;

class Access {
public:
	int pub;
	int pubFunc(int h){ return 0; }
private:
	int priv;
	int privFunc(int h){ return 0; }
protected:
	int prot;
	int protFunc(int h){ return 0; }
};

int main() {
	Access acs;
	int i;

	i = 5;
	acs.pub = i;
	acs.pubFunc(i);
	//acs.priv = i;
	//acs.privFunc(i);
	//acs.prot = i;
	//acs.protFunc(i);
	return 0;
} ///:~
