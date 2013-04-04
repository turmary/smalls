#include <iostream>
#include <cstdio>
using namespace std;

class CEmuBus {
private:
	virtual void CtrlBus() { std::cout << "Control bus : "; }
	virtual void DataBus() { std::cout << "   Data bus : "; }
	virtual void AddrBus() { std::cout << "Address bus : "; }
};

int main() {
	CEmuBus eBus;
	int*	pObject = (int*)(&eBus);		// pObject = 实例指针
	int*	pVtable = (int*)*pObject;		// pVtable = 虚表指针
	typedef void(*Fun)();
	Fun	ptrVfun;				// ptrVfun = 函数指针
	for (int i = 0; i < 3; ++i) {
		ptrVfun = (Fun)*(pVtable+i);		// ptrVfun = p虚函数i
		ptrVfun(); 
		printf("V_function Point = 0x%08X\n",*ptrVfun);
	}
	printf("\neBus对象实例地址 = 0x%08X\n",pObject);
	printf("虚函数表起始地址 = 0x%08X (= [0x%08X])\n",pVtable,pObject);

	printf("虚函数1地址 : [0x%08X] = 0x%08X\n",pVtable,*pVtable );
	printf("虚函数2地址 : [0x%08X] = 0x%08X\n",pVtable+1,*(pVtable+1) );
	printf("虚函数3地址 : [0x%08X] = 0x%08X\n",pVtable+2,*(pVtable+2) );
	printf("虚函数4地址 : [0x%08X] = 0x%08X\n",pVtable+3,*(pVtable+3) );
	return 0;
}
