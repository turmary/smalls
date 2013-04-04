//: T03:T03-31.cpp
//�޸�StringizingExpressions.cpp
//ͨ������һ�������б�־
//ʹ��P(A)����#ifdef�����Զ�ȥ�����Դ���

#include <iostream>
using namespace std;

#ifdef NDEBUG
#define P(A) (A)
#else
#define P(A) cout << #A << ": " << (A) << endl
#endif //NDEBUG

int main() {
	int a = 1, b = 2, c = 3;

#ifdef NDEBUG
	cout <<"NDEBUG defined" <<endl;
#endif //NDEBUG

	P(a); P(b); P(c);
	P(a + b);
	P((c - a)/b);
} ///:~
