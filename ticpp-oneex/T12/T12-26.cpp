//: T12:T12-26.cpp
//修改PointerToMemberOperator.cpp
//加入两个没有参数返回void的成员函数到类Dog
//创建并测试->*对这个新成员函数的操作

#include <iostream>
using namespace std;

class Dog {
public:
	int run(int i) const { 
		cout << "run\n";	
		return i; 
	}
	int eat(int i) const { 
		 cout << "eat\n";	
		 return i; 
	}
	int sleep(int i) const { 
		cout << "ZZZ\n"; 
		return i; 
	}
	int new_first(int i) const {
		cout << "new_first\n";
		return 2 * i;
	}
	int new_second(int i) const {
		cout << "new_second\n";
		return 3 * i;
	}
	typedef int (Dog::*PMF)(int) const;
	// operator->* must return an object 
	// that has an operator():
	class FunctionObject {
		Dog* ptr;
		PMF pmem;
	public:
		// Save the object pointer and member pointer
		FunctionObject(Dog* wp, PMF pmf) 
			: ptr(wp), pmem(pmf) { 
			cout << "FunctionObject constructor\n";
		}
		// Make the call using the object pointer
		// and member pointer
		int operator()(int i) const {
			cout << "FunctionObject::operator()\n";
			return (ptr->*pmem)(i); // Make the call
		}
	};
	FunctionObject operator->*(PMF pmf) { 
		cout << "operator->*" << endl;
		return FunctionObject(this, pmf);
	}
};
 
int main() {
	Dog w;
	Dog::PMF pmf = &Dog::run;
	cout << (w->*pmf)(1) << endl;
	pmf = &Dog::sleep;
	cout << (w->*pmf)(2) << endl;
	pmf = &Dog::eat;
	cout << (w->*pmf)(3) << endl;
	pmf = &Dog::new_first;
	cout << (w->*pmf)(4) << endl;
	pmf = &Dog::new_second;
	cout << (w->*pmf)(5) << endl;
	return 0;
} ///:~
