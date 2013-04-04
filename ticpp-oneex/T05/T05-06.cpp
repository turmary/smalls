//: T05:T05-06.cpp
//创建一个Hen,内嵌Nest类,Nest类内嵌Egg类
//每个类都有成员函数display()

#include <iostream>
using namespace std;

class Hen {
	friend int main();
	class Nest {
		friend int main();
		class Egg {
			friend int main();
			int display(void);
		};
		int display(void);
	};
	int display(void);
};

int Hen::Nest::Egg::display(void) {
	cout <<"Egg::" <<__FUNCTION__ <<"()" <<endl;
	return 0;
}

int Hen::Nest::display(void) {
	cout <<"Nest::" <<__FUNCTION__ <<"()" <<endl;
	return 0;
}

int Hen::display(void) {
	cout <<"Hen::" <<__FUNCTION__ <<"()" <<endl;
	return 0;
}

int main() {
	Hen::Nest::Egg egg;
	Hen::Nest nest;
	Hen hen;

	egg.display();
	nest.display();
	hen.display();
	return 0;
} ///:~
