//: T03:T03-31.cpp
//修改StringizingExpressions.cpp
//通过设置一个命令行标志
//使得P(A)能用#ifdef条件自动去除调试代码

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
