#include <iostream>
#include <ctime>
using namespace std;

class Test {
public:
	Test(int i = 4): m(i) { }
	void show(void) {
		cout <<m <<endl;
	}
	int m;
};

typedef void (* pVoid)();
typedef void (Test::* pTestVoid)();
pTestVoid arr[] = { &Test::show };

int main() {
	Test t(20);

	void* p = arr;
	pVoid pShow = pVoid(*(int*)p);
	t.show();

	time(NULL);

	__asm__ __volatile__ (
#if 0
		"addl\t$4, %%esp\n\t"
		"pushl\t%0\n\t"
#else
		"movl\t%0, %%eax\n\t"
		"movl\t%%eax, (%%esp)"
#endif
		: : "m" (&t): "eax"
	);

	pShow();
	return 0;
}
