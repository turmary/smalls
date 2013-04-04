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
	int*	pObject = (int*)(&eBus);		// pObject = ʵ��ָ��
	int*	pVtable = (int*)*pObject;		// pVtable = ���ָ��
	typedef void(*Fun)();
	Fun	ptrVfun;				// ptrVfun = ����ָ��
	for (int i = 0; i < 3; ++i) {
		ptrVfun = (Fun)*(pVtable+i);		// ptrVfun = p�麯��i
		ptrVfun(); 
		printf("V_function Point = 0x%08X\n",*ptrVfun);
	}
	printf("\neBus����ʵ����ַ = 0x%08X\n",pObject);
	printf("�麯������ʼ��ַ = 0x%08X (= [0x%08X])\n",pVtable,pObject);

	printf("�麯��1��ַ : [0x%08X] = 0x%08X\n",pVtable,*pVtable );
	printf("�麯��2��ַ : [0x%08X] = 0x%08X\n",pVtable+1,*(pVtable+1) );
	printf("�麯��3��ַ : [0x%08X] = 0x%08X\n",pVtable+2,*(pVtable+2) );
	printf("�麯��4��ַ : [0x%08X] = 0x%08X\n",pVtable+3,*(pVtable+3) );
	return 0;
}
