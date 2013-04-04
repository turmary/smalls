//: T05:T05-07.cpp
//修改T05-07.cpp
//使每个类都有private数据成员
//函数display()

#include <iostream>
using namespace std;

class Hen {
public:
	class Nest {
		int val;
		friend class Hen;
	public:
		class Egg {
			int val;
			friend class Nest;
		public:
			int display(void);
		};
		int process(Egg* e);
		int display(void);
	};
	int process(Nest* n);
	int display(void);
};

int Hen::Nest::Egg::display(void) {
	cout <<"Egg::" <<val <<"()" <<endl;
	return 0;
}

int Hen::Nest::process(Egg* e) {
	e->val = 25;
	return 0;
}

int Hen::Nest::display(void) {
	cout <<"Nest::" <<val <<"()" <<endl;
	return 0;
}

int Hen::process(Nest* n) {
	n->val = 17;
}

int Hen::display(void) {
	cout <<"Hen::" <<__FUNCTION__ <<"()" <<endl;
	return 0;
}

int main() {
	Hen::Nest::Egg egg;
	Hen::Nest nest;
	Hen hen;

	hen.process(&nest);
	nest.process(&egg);
	egg.display();
	nest.display();
	hen.display();
	return 0;
} ///:~
